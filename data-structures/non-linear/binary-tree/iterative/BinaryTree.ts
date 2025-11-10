import type { TreeNode } from "../../node/TreeNode";

function preOrderTraversal(root: TreeNode | null): void {
	if (root == null) return;

	const stack: Array<TreeNode> = [];
	let tempNode: TreeNode;
	stack.push(root);

	while (stack.length !== 0) {
		//@ts-expect-error empty array pop returns undefined but that is already checked in the while loop
		tempNode = stack.pop();

		console.log(`${tempNode.getValue()}`);
		if (tempNode.getRight() != null) {
			//@ts-expect-error checking has been done for right being null
			stack.push(tempNode.getRight());
		}

		if (tempNode.getLeft() != null) {
			//@ts-expect-error
			stack.push(tempNode.getRight());
		}
	}
}

function inOrderTraversal(root: TreeNode | null): void {
	if (root == null) return;

	const stack: Array<TreeNode> = [];
	let node: TreeNode | null = root;

	while (node != null || stack.length !== 0) {
		if (node != null) {
			stack.push(node);
			node = node.getLeft();
		} else {
			//@ts-expect-error
			node = stack.pop();
			console.log(`${node?.getValue()}`);
			//@ts-expect-error
			node = node.getRight();
		}
	}
}

function postOrderTraversal(root: TreeNode | null): void {
	const stack: Array<TreeNode> = [];

	let lastVisitedNode: TreeNode | null = null;
	let node: TreeNode | null = root;

	while (node != null || stack.length !== 0) {
		if (node != null) {
			stack.push(node);
			node = node.getLeft();
		} else {
			const top: TreeNode | null = stack[-1];

			if (top.getRight() != null && lastVisitedNode !== top.getRight()) {
				node = top.getRight();
			} else {
				console.log(`${top.getValue()}`);
				lastVisitedNode = top;
				stack.pop();
			}
		}
	}
}

export { inOrderTraversal, postOrderTraversal, preOrderTraversal };
