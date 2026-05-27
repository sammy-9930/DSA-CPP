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

/*
Recursive solution 
time complexity: o(h) h - height of the tree 
space complexity: o(h) h - recursive stack space 
*/
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL)
            return NULL;
        if (val == root->val)
            return root;
        if (val > root->val)
            return searchBST(root->right, val);
        else 
            return searchBST(root->left, val);
    }
};

/*
Iterative solution 
time complexity: o(h)
space complexity: o(1)
*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != NULL){
            if (root->val == val)
                return root;
            else if (val > root->val)
                root = root->right;
            else
                root = root->left;
        }
        return NULL;
    }
};
