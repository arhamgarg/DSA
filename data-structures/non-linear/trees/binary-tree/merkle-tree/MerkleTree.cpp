#include <array>
#include <cstdint>
#include <memory>
#include <vector>

using namespace std;

using Digest = array<uint8_t, 32>;

uint32_t rotateRight(uint32_t value, int bits) {
  return (value >> bits) | (value << (32 - bits));
}

Digest sha256(const vector<uint8_t> &input) {
  static const uint32_t constants[] = {
      0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
      0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
      0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
      0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
      0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
      0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
      0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
      0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
      0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
      0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
      0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};
  array<uint32_t, 8> hash = {0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
                             0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19};
  vector<uint8_t> message = input;
  uint64_t bitLength = static_cast<uint64_t>(message.size()) * 8;

  message.push_back(0x80);
  while (message.size() % 64 != 56) {
    message.push_back(0);
  }
  for (int shift = 56; shift >= 0; shift -= 8) {
    message.push_back(static_cast<uint8_t>(bitLength >> shift));
  }

  for (size_t offset = 0; offset < message.size(); offset += 64) {
    array<uint32_t, 64> words{};
    for (int i = 0; i < 16; i++) {
      for (int byte = 0; byte < 4; byte++) {
        words[i] = (words[i] << 8) | message[offset + i * 4 + byte];
      }
    }
    for (int i = 16; i < 64; i++) {
      uint32_t s0 = rotateRight(words[i - 15], 7) ^
                    rotateRight(words[i - 15], 18) ^ (words[i - 15] >> 3);
      uint32_t s1 = rotateRight(words[i - 2], 17) ^
                    rotateRight(words[i - 2], 19) ^ (words[i - 2] >> 10);
      words[i] = words[i - 16] + s0 + words[i - 7] + s1;
    }

    uint32_t a = hash[0], b = hash[1], c = hash[2], d = hash[3];
    uint32_t e = hash[4], f = hash[5], g = hash[6], h = hash[7];
    for (int i = 0; i < 64; i++) {
      uint32_t s1 = rotateRight(e, 6) ^ rotateRight(e, 11) ^ rotateRight(e, 25);
      uint32_t choice = (e & f) ^ (~e & g);
      uint32_t temp1 = h + s1 + choice + constants[i] + words[i];
      uint32_t s0 = rotateRight(a, 2) ^ rotateRight(a, 13) ^ rotateRight(a, 22);
      uint32_t majority = (a & b) ^ (a & c) ^ (b & c);
      uint32_t temp2 = s0 + majority;
      h = g;
      g = f;
      f = e;
      e = d + temp1;
      d = c;
      c = b;
      b = a;
      a = temp1 + temp2;
    }
    hash[0] += a;
    hash[1] += b;
    hash[2] += c;
    hash[3] += d;
    hash[4] += e;
    hash[5] += f;
    hash[6] += g;
    hash[7] += h;
  }

  Digest digest{};
  for (int i = 0; i < 8; i++) {
    for (int byte = 0; byte < 4; byte++) {
      digest[i * 4 + byte] = static_cast<uint8_t>(hash[i] >> (24 - byte * 8));
    }
  }
  return digest;
}

class MerkleTree {
  struct Node {
    Digest hash;
    unique_ptr<Node> left;
    unique_ptr<Node> right;
  };

public:
  struct ProofStep {
    Digest sibling;
    bool siblingIsLeft;
  };

private:
  unique_ptr<Node> root;

  static unique_ptr<Node> build(const vector<vector<uint8_t>> &data,
                                size_t begin, size_t end) {
    auto node = make_unique<Node>();
    if (end - begin == 1) {
      node->hash = sha256(data[begin]);
      return node;
    }

    size_t middle = begin + (end - begin) / 2;
    node->left = build(data, begin, middle);
    node->right = build(data, middle, end);
    vector<uint8_t> combined(node->left->hash.begin(), node->left->hash.end());
    combined.insert(combined.end(), node->right->hash.begin(),
                    node->right->hash.end());
    node->hash = sha256(combined);
    return node;
  }

  static bool prove(const Node *node, const Digest &leaf,
                    vector<ProofStep> &proof) {
    if (!node->left && node->hash == leaf) {
      return true;
    }
    if (!node->left) {
      return false;
    }
    if (prove(node->left.get(), leaf, proof)) {
      proof.push_back({node->right->hash, false});
      return true;
    }
    if (prove(node->right.get(), leaf, proof)) {
      proof.push_back({node->left->hash, true});
      return true;
    }
    return false;
  }

public:
  explicit MerkleTree(const vector<vector<uint8_t>> &data) {
    if (!data.empty()) {
      root = build(data, 0, data.size());
    }
  }

  Digest getRoot() const { return root ? root->hash : Digest{}; }

  vector<ProofStep> prove(const vector<uint8_t> &item) const {
    vector<ProofStep> proof;
    if (root) {
      prove(root.get(), sha256(item), proof);
    }
    return proof;
  }

  static bool verify(const Digest &rootHash, const vector<uint8_t> &item,
                     const vector<ProofStep> &proof) {
    Digest current = sha256(item);
    for (auto step = proof.rbegin(); step != proof.rend(); ++step) {
      vector<uint8_t> combined;
      if (step->siblingIsLeft) {
        combined.insert(combined.end(), step->sibling.begin(),
                        step->sibling.end());
        combined.insert(combined.end(), current.begin(), current.end());
      } else {
        combined.insert(combined.end(), current.begin(), current.end());
        combined.insert(combined.end(), step->sibling.begin(),
                        step->sibling.end());
      }
      current = sha256(combined);
    }
    return current == rootHash;
  }
};
