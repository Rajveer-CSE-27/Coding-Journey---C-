/**
Problem : iven an array of integers arr[] and an integer target. Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.
Approach 1 :: 2 loops approach. Time : O(n^2) , Space : O(1)
Approach 2 :: Sort + 2 pointers. Time : O(n*logn) + O(n), Space : O(1)
Approach 3 :: Hashing. Time : O(n*logn) if ordered set, O(n) if unordered set, Space : O(n)

**/

#include <bits/stdc++.h>
using namespace std;

bool approach1(int n, vector<int>& arr, int target) {
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] + arr[j] == target) {
                return true;
            }
        }
    }
    return false;
}

bool approach2(int n, vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    int l=0, r = n-1;
    
    while(l < r) {
        // we dont take l==r because we want 2 different elements to sum up
        if(arr[l] + arr[r] == target) {
            return true;
        }
        
        if(arr[l] + arr[r] < target) {
            l++;
        } else {
            r--;
        }
    }
    return false;
}

bool approach3(int n, vector<int>& arr, int target) {
    unordered_set<int> st;
    for(int i=0; i<n; i++) {
        st.insert(arr[i]);
    }
    
    for(int i=0; i<n; i++) {
        if(st.find(target - arr[i]) != st.end()) {
            return true;
        }
    }
    return false;
}

int main() {
    int n = 5, target = 14;
    vector<int> arr = {2, 6, 5, 8, 11};
    
    bool ans1 = approach1(n,arr,target);
    string out1 = (ans1) ? "YES" : "NO";
    cout << out1 << endl;
    
    
    bool ans2 = approach2(n,arr,target);
    string out2 = (ans2) ? "YES" : "NO";
    cout << out2 << endl;
    
    bool ans3 = approach3(n,arr,target);
    string out3 = (ans3) ? "YES" : "NO";
    cout << out3 << endl;
    
    
    return 0;
}
