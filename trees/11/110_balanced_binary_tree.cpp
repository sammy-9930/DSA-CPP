/*
Depth first search
Time complexity : O(n)
Space complexity : O(n)
*/
class Solution {
public:
    int helper(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int left = helper(root->left);
        if (left == -1) return -1;
        
        int right = helper(root->right);
        if(right == -1) return -1;

        if(abs(left - right) > 1){
            return -1;
        }
        
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return helper(root) == -1 ? false : true;
    }
};
