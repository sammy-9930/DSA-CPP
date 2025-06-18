/*
Time complexity: O(logn)
Space complexity: O(1)
*/

#include <iostream>
#include <vector>

int binary_search(const std::vector<int> &arr, int target){
    int low = 0;
    int high = arr.size() - 1; 
    while (low < high){
        int mid = (low + high) / 2;
        if (target == arr[mid]){
            return mid;
        }
        else if (target < arr[mid]){
            high = mid - 1; 
        }
        else{
            low = mid + 1; 
        }
    }
    return -1;
}


int main(){
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15};
    int target = 7; 
    int result = binary_search(arr, target);
    if (result == -1){
        std::cout<<"Number not found";
    }
    else{
        std::cout << "Number found at index: " << result; 
    }
    return 0;
}