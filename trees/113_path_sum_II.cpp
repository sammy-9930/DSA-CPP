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
    void helper(TreeNode* root, int targetSum, vector<vector<int>>& res, vector<int> cur){
        if(root == nullptr)
            return;

        if(root->left == nullptr && root->right == nullptr && root->val == targetSum){
            cur.push_back(root->val);
            res.push_back(cur);
        }
        
        cur.push_back(root->val);

        helper(root->left, targetSum - root->val, res, cur);
        helper(root->right, targetSum - root->val, res, cur);

        cur.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(root, targetSum, res, cur);
        return res;
    }
};


