#include <iostream>
#include <queue>
#include <vector>

/* From this line to https://www.programiz.com/dsa/binary-search-tree*/
struct node {
	int key;
	struct node* left, * right;
};

struct node* newNode(int item) {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(struct node* root) {
	if (root != NULL) {
		inorder(root->left);
		std::cout << root->key << " -> ";
		inorder(root->right);
	}
}

struct node* insert(struct node* node, int key) {
	if (node == NULL) return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	return node;
}

struct node* minValueNode(struct node* node) {
	struct node* current = node;

	while (current && current->left != NULL)
		current = current->left;

	return current;
}

struct node* deleteNode(struct node* root, int key) {
	if (root == NULL) return root;
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else {
		if (root->left == NULL) {
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}
		struct node* temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}
/* to the this line source: https://www.programiz.com/dsa/binary-search-tree*/

void printBT(const std::string& prefix, const struct node* node, bool isLeft)
{
	if (node != nullptr)
	{
		std::cout << prefix;
		std::cout << (isLeft ? "|----" : "L----");
		// print the value of the node
		std::cout << node->key << std::endl;
		// enter the next tree level - left and right branch
		printBT(prefix + (isLeft ? "|   " : "    "), node->right, true);
		printBT(prefix + (isLeft ? "|   " : "    "), node->left, false);
	}
}

void DFS_inorder(struct node* node, std::vector<int>& list) {
	if (node->left)
		DFS_inorder(node->left, list);
	list.push_back(node->key);
	if (node->right)
		DFS_inorder(node->right, list);
}

void DFS_preorder(struct node* node, std::vector<int>& list) {
	list.push_back(node->key);

	if (node->left)
		DFS_preorder(node->left, list);

	if (node->right)
		DFS_preorder(node->right, list);
}

void DFS_postorder(struct node* node, std::vector<int>& list) {
	if (node->left)
		DFS_postorder(node->left, list);

	if (node->right)
		DFS_postorder(node->right, list);
	list.push_back(node->key);

}
void print_vec(std::vector<int>& list) {
	std::cout << "\n[";
	for (int element : list)
	{
		std::cout << element << " ";
	}
	std::cout << "]\n";
}

int main() {
	struct node* root = NULL;
	root = insert(root, 8);
	root = insert(root, 3);
	root = insert(root, 1);
	root = insert(root, 6);
	root = insert(root, 7);
	root = insert(root, 10);
	root = insert(root, 14);
	root = insert(root, 4);

	printBT("", root, false);

	std::vector<int>inorder{};
	std::vector<int>preorder{};
	std::vector<int>postorder{};
	DFS_inorder(root, inorder);
	DFS_preorder(root, preorder);
	DFS_postorder(root, postorder);

	print_vec(inorder);
	print_vec(preorder);
	print_vec(postorder);


}