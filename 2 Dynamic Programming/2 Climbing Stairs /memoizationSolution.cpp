/**
Problem Statement : Given a number of stairs. 
                    Starting from the 0th stair we need to climb to the “Nth” stair. 
                    At a time we can climb either one or two steps. 
                    We need to return the total number of distinct ways to reach from 0th to Nth stair.

Approach : Convert the previous recursion solution to DP Memoization.
           
Time Complexity : O(n) , maximum it computes once for each stair from 0 to N.
Space Complexity : O(n) for storing value of each stair + O(n) recursion auxillary stack space 
**/

#include <bits/stdc++.h>
using namespace std;

int stairs(int n, vector<int>& dp) {
    if(n <= 1) {
        // edge case we can reach 0th stair in only 1 way and 1st stair in only 1 way
        dp[n] = 1;
        return 1;
    }
    
    if(dp[n] != -1) {
        return dp[n];
    }
    
    return dp[n] = stairs(n-1, dp) + stairs(n-2, dp);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> dp(n+1, -1);
    
    int ans = stairs(n, dp);
    cout << ans;
    return 0;
}
