// Question Link: https://leetcode.com/problems/longest-univalue-path

// O(N) Solution
int longestUnivaluePath(TreeNode* root) {
	int longestUniPathLength = 0;
	helper(root, longestUniPathLength);
	return longestUniPathLength;
}

// Returns the current uni path length to parent
int helper(TreeNode* cur, int &maxPathLength) {
	if (cur == NULL) {
		return 0;
	}
	int leftPath = helper(cur->left, maxPathLength);
	int rightPath = helper(cur->right, maxPathLength);
	int leftPathLengthIncludingCurrentNode = 0;
	int rightPathLengthIncludingCurrentNode = 0;
	// Check if we are also part of the left path
	if (cur->left && cur->left->val == cur->val) {
		leftPathLengthIncludingCurrentNode = leftPath + 1;
	}
	// Check if we are also part of the right path
	if (cur->right && cur->right->val == cur->val) {
		rightPathLengthIncludingCurrentNode = rightPath + 1;
	}
	// Update maxPathLength result
	maxPathLength = max(maxPathLength, leftPathLengthIncludingCurrentNode + rightPathLengthIncludingCurrentNode);
	// We return the longest path between us and one other node, we don't return the longest path found!
	return max(leftPathLengthIncludingCurrentNode, rightPathLengthIncludingCurrentNode);
}

// O(N^2 Solution)
int longestUnivaluePath(TreeNode* root) {
	int longestUniPathLength = 0;
	traverse(root, longestUniPathLength);
	return longestUniPathLength;
}

// Keep going as long as we see same node values with val, and return max path length
int keepGoing(TreeNode* cur, int &val) {
	if (cur == NULL || (cur && cur->val != val)) {
		return 0;
	}
	return 1 + max(keepGoing(cur->left, val), keepGoing(cur->right, val));
}

// Traverse each node and find max uni path
void traverse(TreeNode* cur, int &maxPathLength) {
	if (cur == NULL) {
		return;
	}
	int pathSum = keepGoing(cur->left, cur->val) + keepGoing(cur->right, cur->val);
	maxPathLength = max(maxPathLength, pathSum);
	traverse(cur->left, maxPathLength);
	traverse(cur->right, maxPathLength);
}
