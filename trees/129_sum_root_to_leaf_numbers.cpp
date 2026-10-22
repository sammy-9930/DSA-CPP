/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* curNode, int sum){
        if (curNode == nullptr)
            return 0;
        
        if(curNode->left || curNode->right)
            return helper(curNode->left, sum*10 + curNode->val) + helper(curNode->right, sum*10 + curNode->val);
        
        return sum*10 + curNode->val;
    }

    int sumNumbers(TreeNode* root) {
        int sum = helper(root, 0);
        return sum;
    }
};
