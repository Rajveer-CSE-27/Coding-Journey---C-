/**
Problem Statement : We are given an array ‘ARR’ with N positive integers. 
                    We need to find if we can partition the array into two subsets, 
                    such that the sum of elements of each subset is equal to the other.
                    
Approach :  Using memoization over recursion.

Time Complexity =  O(n*k)
Space Complexity = O(n*k) + O(n) 
**/

#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& vc, int index, int k, vector<vector<int>>& dp) {
    if(index == -1) {
        return false;
    }
    if(k == 0) {
        return dp[index][k] = true;
    }
    if(dp[index][k] != -1) {
        return dp[index][k];
    }
    
    bool not_pick = solve(vc, index-1, k, dp);
    bool pick = false;
    if(k >= vc[index]) {
        pick = solve(vc, index - 1, k - vc[index], dp);
    }
    return dp[index][k] = not_pick or pick;
}

int main() {
    
    int n, sm = 0;
    cin >> n;
    vector<int> vc(n);
    for(int i=0; i<n; i++) {
        cin >> vc[i];
        sm += vc[i];
    }
    bool ans = false;
    if(sm%2 == 0) {
        int k = sm/2;
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        ans = solve(vc, n-1, k, dp);
    }
    
    (ans) ? cout << "YES\n" : cout << "NO\n";
    
}
