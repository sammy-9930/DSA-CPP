/*
Brute  force
time: O(m*n)
space: O(1)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == target){
                    return true;
                }
            }
        }
        return false;
    }
};

/*
Binary search optimized 
time: O(log(m*n))
space: O(1)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low = 0;
        int high = (rows*cols)-1;
        while (low <= high){
            int mid = (low+high)/2;
            int c_row = mid / cols;
            int c_col = mid % cols;
            if (target == matrix[c_row][c_col]){
                return true;
            }
            else if (target < matrix[c_row][c_col]){
                high = mid - 1;
            }  
            else{
                low = mid + 1;
            }
        }
        return false;
    }
};
