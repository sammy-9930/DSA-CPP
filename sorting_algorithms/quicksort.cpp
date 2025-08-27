#include <iostream>
#include <vector>
using namespace std;
/*
time : O(n^2) - List is already sorted 
       O(n^2) - worst case  [n, n-1, n-2 ... 2 1] 
       O(nlogn) - best case 

       Best case - partitioning done in the center - o(nlogn)
       worst case - partitioning done at any end - o(n^2) in terms of element arrangement 
*/

int partition(vector<int>& arr, int low, int high){
    int i = low + 1; // or i = low
    int j = high;
    int pivot = arr[low];

    while (i <= j){
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
