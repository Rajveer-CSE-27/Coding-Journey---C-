/**
Problem Statement : Given a number of stairs. 
                    Starting from the 0th stair we need to climb to the “Nth” stair. 
                    At a time we can climb either one or two steps. 
                    We need to return the total number of distinct ways to reach from 0th to Nth stair.

Approach : Convert the previous Memoization solution to DP Tabulation for excluding the recursion.
           
Time Complexity : O(n) , maximum it computes once for each stair from 0 to N.
Space Complexity : O(n) for storing value of each stair.
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    
    vector<int> dp(n+1, -1);
    dp[0] = 1;
    dp[1] = 1;
    // edge cases in memoization.
    
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    cout << dp[n];
    return 0;
}
