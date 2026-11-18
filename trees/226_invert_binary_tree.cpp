// BFS 
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
Breadth first search
Time complexity : O(n)
Space complexity : O(n)
*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* frontNode = q.front();
            q.pop();

            swap(frontNode->left, frontNode->right);

            if(frontNode->left)
                q.push(frontNode->left);
            
            if(frontNode->right)
                q.push(frontNode->right);
        }
        return root;
    }
};

/*
DFS 
Time complexity : O(n) 
Space complexity : O(n) for recursive stack
*/
class Solution {
public:
    void helper(TreeNode* root){
        if (root == nullptr) return;
        swap(root->left, root->right);
        helper(root->left);
        helper(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        helper(root);
        return root;
    }
};
