class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // number of rows 
        int m = matrix.size();
        // number of columns 
        int n = matrix[0].size();

        int left = 0;
        int right = (m * n) - 1;

        while (left <= right){
            int mid = (left + right) / 2;
            int row = mid / n;
            int col = mid % n; 
            if (target == matrix[row][col])
                return true;
            else if (target < matrix[row][col])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};