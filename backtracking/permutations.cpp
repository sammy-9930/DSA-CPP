// with extra space 
class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& result, vector<int> curr, vector<bool>& visited){
        // base cond 
        if (curr.size() == nums.size()){
            result.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if (visited[i])
                continue; 
            visited[i] = true; 
            curr.push_back(nums[i]);
            
            helper(nums, result, curr, visited);

            curr.pop_back();
            visited[i] = false;
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        vector<bool> visited(nums.size(), false);
        helper(nums, result, curr, visited);
        return result;
    }
};

// without extra space - preferred
class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& result, int idx){
        if (idx == nums.size()){
            result.push_back(nums);
            return;
        }

        for(int i = idx; i < nums.size(); i++){
            swap(nums[idx], nums[i]);
            helper(nums, result, idx+1);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        helper(nums, result, 0);
        return result;
    }
};
