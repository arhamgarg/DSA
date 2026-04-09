package main

import (
	"crypto/sha256"
	"encoding/hex"
	"fmt"
	"strings"
)

// SHA-256 hash results in 256 bits which is equal to 32 bytes
const DIGEST_SIZE = 32

type merkleNode struct {
	data  [DIGEST_SIZE]byte // holds the hash of left and right children
	left  *merkleNode
	right *merkleNode
}

type MerkleTree struct {
	root merkleNode
}

type MerkleProof struct {
	// List of hashes that constitute the proof
	hashes [][DIGEST_SIZE]byte
	// The side each has is on (left = true, right = false)
	left []bool
}

func NewMt(data [][]byte) *MerkleTree {
	// No nodes
	if len(data) == 0 {
		return nil
	}

	// Leaf node condition
	if len(data) == 1 {
		leaf := merkleNode{
			data:  sha256.Sum256(data[0]),
			left:  nil,
			right: nil,
		}

		tree := MerkleTree{root: leaf}
		return &tree
	}

	// Non-leaf node condition. Construct a full tree.
	left := NewMt(data[:len(data)/2])
	right := NewMt(data[len(data)/2:])

	// Concatenating two byte arrays into a combined array for hashing at root
	combined := append(left.root.data[:], right.root.data[:]...)
	rootData := sha256.Sum256(combined)

	root := merkleNode{
		data:  rootData,
		left:  &left.root,
		right: &right.root,
	}
	tree := MerkleTree{root}

	return &tree
}

func (root *merkleNode) search(item []byte) []*merkleNode {
	// Base Case. If there is no left and right child, then hash the bytes[]
	if root.left == nil && root.right == nil {
		if root.data == sha256.Sum256(item) {
			return []*merkleNode{root}
		} else {
			return nil
		}
	}

	// Search in left and right subtrees
	left := root.left.search(item)
	right := root.right.search(item)

	if left != nil {
		path := append(left, root)
		return path
	} else if right != nil {
		path := append(right, root)
		return path
	}

	// If it does not exist in either subtree, it isn't in the tree at all
	return nil
}

func (root *merkleNode) size() int {
	if root.left == nil && root.right == nil {
		return 1
	}
	return root.left.size() + root.right.size()
}

// Generator function for finding whether an item is part of the Merkle tree or
// not
func (tree *MerkleTree) Prove(item []byte) *MerkleProof {
	// Find the leaf corresponding to the item inside the tree. In this
	// process you en up tracing the entire path as you go along.
	path := tree.root.search(item)

	// Tracks where we are in the tree
	node := path[len(path)-1]

	// empty arrays for tracking hashes and left/right children along the path
	hashes := [][DIGEST_SIZE]byte{}
	left := []bool{}

	for i := len(path) - 2; i >= 0; i-- {
		curr_node := path[i]
		// If the next node in the path is a left hcild of the current node,
		// append the data inside the "right" child
		if node.left.data == curr_node.data {
			hashes = append(hashes, node.right.data)
			left = append(left, false)
		} else if node.right.data == curr_node.data {
			hashes = append(hashes, node.left.data)
			left = append(left, true)
		}
		node = curr_node
	}

	return &MerkleProof{hashes: hashes, left: left}
}

func (proof *MerkleProof) Verify(root [DIGEST_SIZE]byte, item []byte) bool {
	// The current hash (by the final iteration, we ought to have it equal to
	// the root hash).
	acc := sha256.Sum256(item)
	for i := len(proof.hashes) - 1; i >= 0; i-- {
		if proof.left[i] {
			cat := append(proof.hashes[i][:], acc[:]...)
			acc = sha256.Sum256(cat)
		} else {
			cat := append(acc[:], proof.hashes[i][:]...)
			acc = sha256.Sum256(cat)
		}
	}

	return acc == root
}

func (tree *MerkleTree) Root() [DIGEST_SIZE]byte {
	return tree.root.data
}

func (tree *MerkleTree) Print() {
	tree.root.print(0)
}

func (root *merkleNode) print(depth int) {
	if root == nil {
		return
	}

	// In-order traversal
	root.left.print(depth + 1)
	fmt.Printf("%s%s\n", strings.Repeat("   ", depth), hex.EncodeToString(root.data[:]))
	root.right.print(depth + 1)
}

const N_ITEMS = 8

func main() {
	data := make([][]byte, 0)

	// Seeding
	for i := range N_ITEMS {
		// Turn each data point into bytes. This works because an integer is a byte
		data = append(data, []byte(fmt.Sprint(i)))
	}

	// Create a tree and print it's contents
	mt := NewMt(data)
	mt.Print()

	// Verify a valid proof
	pf := mt.Prove([]byte(fmt.Sprint(5)))
	fmt.Printf("Result for proof: %v\n", pf.Verify(mt.Root(), []byte(fmt.Sprint(5))))
}
