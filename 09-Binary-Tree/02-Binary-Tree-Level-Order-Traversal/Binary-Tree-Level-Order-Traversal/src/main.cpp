#include <iostream>
#include <vector>
#include <Queue>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 std::vector<std::vector<int>> tree_breadth_first_search(TreeNode* root)
{
     if (!root)
         return std::vector<std::vector<int>>{};

    std::vector<std::vector<int>> result;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.size()<1)
    {
        int length = q.size();
        int count = 0;
        std::vector<int> current_values_container;
        while (length> count)
        {
            TreeNode* current_node= q.front();
            q.pop();
            current_values_container.push_back(current_node->val);
            if (current_node->left != NULL)
                q.push(current_node->left);
            if (current_node->right != NULL)
                q.push(current_node->right);
            count++;
        }
        result.push_back(current_values_container);
    }

    return result;
    
}

int main()
{
    std::cout << "Hello World!\n";
}
