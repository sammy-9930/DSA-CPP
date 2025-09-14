/*
Select a position and find an element for that position.
For n elements, n-1 swaps, so O(N)
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void selection_sort(vector<int>& a){
    for(int i = 0; i < a.size() - 1 ; i++){
        int k = i;
        for(int j = i; j < a.size(); j++){
            if (a[j] < a[k]){
                k = j;
            }
        }
        swap(a[i], a[k]);
    }
}

int main(){
    vector<int> a = {8, 6, 3, 2, 5, 4};
    cout << "Before sorting\n";
    for (auto number: a){
        cout << number << " ";
    }
    selection_sort(a);
    cout << "\nAfter sorting\n";
    for (auto number: a){
        cout << number << " ";
    }
}