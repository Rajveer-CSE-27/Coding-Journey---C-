// Question : Given an array, and an element num the task is to find if num is present in the given array or not. If present print the index of the element or print -1.
// Approach 1 : Linear search , Time : O(n) ,  space : O(1)


#include <bits/stdc++.h>
using namespace std;


int main() {
    
    int n , target;
    cin >> n >> target;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        
    }
    
    int index = 0;
    while(index < n) {
        if(arr[index] == target) {
            cout << index << endl;
            break;
        }
        index++;
    }
    
    if(index == n) {
        cout << -1 << endl;
    }
    
    return 0;
}
