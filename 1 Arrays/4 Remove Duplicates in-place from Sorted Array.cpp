// Question : Remove Duplicates in-place from Sorted Array
// Approach : Single iteration and go on removing the current element if repeating
// Time complexity ; O(N) , Space Complexity :: O(1)

#include <bits/stdc++.h>
using namespace std;


int main() {
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        
    }
    
    int j = 0; // pointer to the last unique element in array
    int i=0;
    while(i < n-1) {
        if(arr[i+1] > arr[i]) {
            j++;
            arr[j] = arr[i+1];
        }
        i++;
    }
    
    for(int k=0; k<=j; k++) {
        cout << arr[k] << " ";
    }
    
    return 0;
}
