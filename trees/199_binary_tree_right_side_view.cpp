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

// BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int> cur;
            for(int i = 0; i < s; i++){
                TreeNode* frontNode = q.front();
                q.pop();
                cur.push_back(frontNode->val);
                if(frontNode->left)
                    q.push(frontNode->left);
                if(frontNode->right)
                    q.push(frontNode->right);
            }
            int element = cur[cur.size()-1];
            res.push_back(element);
        }
        return res;
    }
};

// DFS
class Solution {
public:
    void helper(TreeNode* root, vector<int>& res, int depth){
        if(root == nullptr) return;

        if(depth == res.size()){
            res.push_back(root->val);
        }

        helper(root->right, res, depth+1);
        helper(root->left, res, depth+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        helper(root, res, 0);
        return res;
    }
};
