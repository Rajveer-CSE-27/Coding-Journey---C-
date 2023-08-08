// Question : Rotate array by K elements
// Approach 1 : Make another array -> Time : O(n) , Space = O(n)
// Approach 2 : Make array of only k size and move all previous n-k elements right and copy k elements in beginning of array -> time : O(n) , space = O(k)
// Approach 3 : Reverse first n-k elements and last k elements individually and then reverse whole array once -> time : O(n) space : O(1)


#include <bits/stdc++.h>
using namespace std;

void rev(int l, int r, vector<int>& arr) {
    while(l < r) {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

void approach3(int n, vector<int>& arr, int k) {
    rev(0,n-k-1,arr);
    rev(n-k,n-1,arr);
    rev(0,n-1,arr);
    
}

int main() {
    
    int n , k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        
    }
    
    approach3(n,arr,k);
    
    for(auto it:arr) {
        cout << it << " ";
    }
    
    return 0;
}
