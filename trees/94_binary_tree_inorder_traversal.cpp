/*
Recursive solution
Time complexity: O(n)
Space complexity: O(n) for the recursion stack, O(n) for output array
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
        
        if (root->left)
            helper(root->left, res);
        
        res.push_back(root->val);
        
        if (root->right)
            helper(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        helper(root, res);
        return res;
    }
};

/*
Iterative DFS
Time complexity: O(n)
Space complexity: O(n) for stack, O(n) for the output array
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;
        TreeNode* cur = root;

        while(cur || !stack.empty()){
            while(cur){
                stack.push(cur);
                cur = cur->left;
            }

            cur = stack.top();
            stack.pop();
            res.push_back(cur->val);

            cur = cur->right;
        }
        return res;
    }
};
