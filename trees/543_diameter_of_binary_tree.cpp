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
// DFS
class Solution {
public:
    int helper(TreeNode* root, int& diameter){
        if(root == nullptr) return 0;
        
        int leftMax = helper(root->left, diameter);
        int rightMax = helper(root->right, diameter);

        int curMax = leftMax + rightMax;
        diameter = max(diameter, curMax);
        
        return 1 + max(leftMax, rightMax);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int diameter = 0;
        helper(root, diameter);
        return diameter;
    }
};
