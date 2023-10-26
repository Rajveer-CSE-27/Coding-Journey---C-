/**
Problem Statement : We are given an array ‘ARR’ with N positive integers.
                    We need to find if there is a subset in “ARR” with a sum equal to K. 
                    If there is, return true else return false.
                    
Approach : Use memoization to save time.

Time Complexity =  O(n*k) becuase we will consider all possible sums from all indices.
Space Complexity = O(n*k) dp space + O(n) : auxillary stack space.
**/

#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& vc, int i, int k, vector<vector<int>>& dp) {
    if(i == -1) {
        return false;
    }
    if(k == 0) {
        return dp[i][k] = true;
    }
    if(dp[i][k] != -1) {
        return dp[i][k];
    }
    
    bool not_pick = solve(vc, i-1, k, dp);
    bool pick = false;
    if(k >= vc[i]) {
        pick = solve(vc, i-1, k - vc[i], dp);
    }
    
    return dp[i][k] = not_pick or pick;
}

int main() {
    
    int n, k;
    cin >> n >> k;
    vector<int> vc(n);
    for(int i=0; i<n; i++) {
        cin >> vc[i];
    }
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    // yaha hum bool dp nahi le rahe kyuki fir initial false me aur answer false me konsa false sahi hai vo confusion hoga
    
    bool ans = solve(vc, n-1, k, dp);
    (ans) ? cout << "YES\n" : cout << "NO\n";
     
    return 0;
}
