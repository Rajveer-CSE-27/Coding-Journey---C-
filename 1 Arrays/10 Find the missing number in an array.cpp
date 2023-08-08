/** 
Question : Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. Find the number(between 1 to N), that is not present in the given array.
Approach 1 : Brute force . Find each element from 1 to n in the array -> Time : O(n^2) , space : O(1)
Approach 2 : Sort and iterate . -> Time : O(n*logn) , Space : O(1)
Approach 3 : Sum and find the difference -> Time : O(n) , Space : O(1)
Approach 4 : Xor the array values with values from 1 to n -> Time : O(n) , Space : O(1)
**/

#include <bits/stdc++.h>
using namespace std;

int approach3(int n, int arr[]) {
    int sm = 0, smArr = 0;
    
    for(int i=1; i<=n; i++) {    
        sm += i;
    }
    
    for(int i=0; i<n-1; i++) {
        smArr += arr[i];
    }
    
    return sm - smArr;
    
}

int approach2(int n, int arr[]) {
    int xr = 0;
    for(int i=1; i<=n; i++) {
        xr ^= i;
    }
    for(int i=0; i<n-1; i++) {
        xr ^= arr[i];
    }
    return xr;
}

int main() {
    
    int n;
    cin >> n;
    int arr[n-1];
    for(int i=0; i<n-1; i++) {
        cin >> arr[i];
    }
    
    int ans1 = approach3(n,arr);
    cout << ans1 << endl;
    
    int ans2 = approach2(n,arr);
    cout << ans2 << endl;
    
    
    return 0;
}
