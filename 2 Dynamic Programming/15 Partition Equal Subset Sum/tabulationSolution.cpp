/**
Problem Statement : We are given an array ‘ARR’ with N positive integers. 
                    We need to find if we can partition the array into two subsets, 
                    such that the sum of elements of each subset is equal to the other.
                    
Approach :  Using tabulation over memoization.

Time Complexity =  O(n*k)
Space Complexity = O(n*k). 
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n, sm = 0;
    cin >> n;
    vector<int> vc(n);
    for(int i=0; i<n; i++) {
        cin >> vc[i];
        sm += vc[i];
    }
    
    if(sm&1) {
        cout << "NO\n";
        return 0;
    }
    
    vector<vector<bool>> dp(n, vector<bool>(sm+1,false));
    for(int i=0; i<n; i++) {
        dp[i][0] = true;
    }
    dp[0][vc[0]] = true;
    
    for(int i=1; i<n; i++) {
        for(int target=1; target<=sm; target++) {
            bool not_pick = dp[i-1][target];
            bool pick = false;
            if(target >= vc[i]) {
                pick = dp[i-1][target - vc[i]];
            }
            dp[i][target] = not_pick or pick;
        }
    }
    
    (dp[n-1][sm/2]) ? cout << "YES\n" : cout << "NO\n";
}
