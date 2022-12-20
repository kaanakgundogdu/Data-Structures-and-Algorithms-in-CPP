#include <iostream>
#include <cmath>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};

int max_depth(TreeNode* root, int current_depth) {

	if (!root)
		return current_depth;

	current_depth++;

	return std::max(max_depth(root->left, current_depth), max_depth(root->right, current_depth));
}

int maxDepth(TreeNode* root) {
	return max_depth(root,0);
}


int main()
{
	std::cout << "Hello World!\n";
}
