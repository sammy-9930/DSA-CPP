#include <iostream>
#include <vector>

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
private:
    void inorder(TreeNode* current, std::vector<int>& result){
        if (current == nullptr)
            return; 
        inorder(current->left, result);
        result.push_back(current->val);
        inorder(current->right, result);
    }
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        inorder(root, result);
        return result;
    }
};