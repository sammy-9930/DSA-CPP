#include <iostream>
#include <vector>
using namespace std;
/*
time : O(n^2) - List is already sorted 
       O(n^2) - worst case  [n, n-1, n-2 ... 2 1] 
       O(nlogn) - best case 

       Best case - partitioning done in the center - o(nlogn)
       worst case - partitioning done at any end - o(n^2) 
       all the elements come into one side of the pivot [balance affects depth of the tree]
*/

int partition(vector<int>& arr, int low, int high){
    int i = low + 1; // or i = low
    int j = high;
    int pivot = arr[low];

    while (i < j){
        while(i <= high && arr[i] <= pivot){
            i++;
        }
        while(j >= low && arr[j] > pivot){
            j--;
        }
        if (i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quicksort(vector<int>& arr, int low, int high){
    // process array with more than 1 element
    if (low < high){
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

int main(){
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();
    cout << "Before sorting" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    quicksort(arr, 0, n-1);

    cout << "After sorting" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


// using last element as pivot

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int i = low, j = high - 1;

    while (i <= j){
        while(i <= j && arr[i] <= pivot){
            i++;
        }
        while(i <= j && arr[j] > pivot){
            j--;
        }
        if (i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[high], arr[i]);
    return i;
}

void quicksort(vector<int>& arr, int low, int high){
    // process array with more than 1 element
    if (low < high){
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

int main(){
    vector<int> arr = {50, 60, 70, 80, 40, 30, 20};
    int n = arr.size();
    cout << "Before sorting" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    quicksort(arr, 0, n-1);

    cout << "After sorting" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


/*Using middle element as pivot*/
class Solution {
public:
    int partition(vector<int>& nums, int low, int high){
        int mid = (low + high) / 2;
        int pivot = nums[mid];
        swap(nums[low], nums[mid]);

        int i = low;
        int j = high;

        while (i < j){
            while (i <= high && nums[i] <= pivot){
                i ++;
            }
            while (j >= low && nums[j] > pivot){
                j --;
            }
            if (i < j){
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[low], nums[j]);
        return j;
    }
    void quicksort(vector<int>& nums, int low, int high){
        if(low < high){
            int pi = partition(nums, low, high);
            quicksort(nums, low, pi-1);
            quicksort(nums, pi+1, high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quicksort(nums, 0, n-1);
        return nums;
    }
};