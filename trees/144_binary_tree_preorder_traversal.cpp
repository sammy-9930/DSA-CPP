/*
Recursive solution
Time complexity: O(n)
Space complexity: O(n) for recursive stack, O(n) for output array
*/
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
    void helper(TreeNode* root, vector<int>& res){
        if (root == NULL) return;
        
        res.push_back(root->val);
        
        if (root->left)
            helper(root->left, res);
        
        if (root->right)
            helper(root->right, res);

    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        helper(root, res);
        return res;
    }
};


/*
Iterative DFS
Time complexity: O(n)
Space complexity: O(n) for recursive stack, O(n) for output array
*/
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* frontNode = stk.top();
            res.push_back(frontNode->val);
            stk.pop();
            if (frontNode->right)
                stk.push(frontNode->right);
            if (frontNode->left)
                stk.push(frontNode->left);
        }
        return res;
    }
};
