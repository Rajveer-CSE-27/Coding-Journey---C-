/** 
Question : Find the number that appears once, and the other numbers twice
Approach 1 : Brute force. Search for every element in the array. -> Time : O(n^2) , Space : O(1)
Approach 2 : Sort and iterate. -> Time : O(n*logn) , Space : O(1)
Approach 3 : Using hash map to store frequency. -> Time : O(n), Space : O(n)
Approach 4 : Xor + Linear iterate -> Time : O(n) , Space : O(1) 
**/

#include <bits/stdc++.h>
using namespace std;

int approach3(int n, int arr[]) {
    map<int,int> mp;
    for(int i=0; i<n; i++) {
        mp[arr[i]]++;
    }
    for(auto it:mp) {
        if(it.second == 1) {
            return it.first;
        }
    }
    return -1;
}

int approach4(int n, int nums[]) {
    int xr = 0;
    for(int i=0; i<n; i++) {
        xr ^= nums[i];
    }
    return xr;
}

int main() {
    
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    int ans = approach3(n, arr);
    cout << ans << endl;
    
    int ans2 = approach4(n,arr);
    cout << ans2 << endl;
    
    return 0;
}
