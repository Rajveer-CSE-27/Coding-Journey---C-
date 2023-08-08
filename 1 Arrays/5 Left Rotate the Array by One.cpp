// Question : Left Rotate the Array by One
// Approach : Go on shifting all elements from 2 to n one step left and at the end fill the value of initial first inddex value to last element of array
// Time complexity ; O(N) , Space Complexity :: O(1)

#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& arr) {
    // edge case
    if(n <= 1) {
        return;
    }
    
    int temp = arr[0];
    for(int i=1; i<n; i++) {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
    
}

int main() {
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        
    }
    
    solve(n,arr);
    
    for(auto it:arr) {
        cout << it << " ";
    }
    
    return 0;
}
