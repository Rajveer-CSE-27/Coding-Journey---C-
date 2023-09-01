/**
Problem Statement : This is a follow-up question to “Frog Jump”. 
                    In the previous question, the frog was allowed to jump either one or two steps at a time. 
                    In this question, the frog is allowed to jump up to ‘K’ steps at a time. 
                    If K=4, the frog can jump 1,2,3, or 4 steps at every index.

Approach :  We will apply memoization over the recursion solution to save the time.


Time Complexity = O(n * k) because for each index we will be iterating to all possible k previous indices to get minimum jump.
Space Complexity = O(n) : space for storing answers of each index + O(n) : auxillary stack space.

**/

#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& height, int k, vector<int>& dp) {
    if(n == 0) {
        dp[0] = 0;
        return 0;
        // base case
    }
    if(dp[n] != -1) {
        return dp[n];
        //memoization step
    }
    
    
    int minSteps = INT_MAX;
    
    for(int i=1; i<=k; i++) {
        if(n >= i) {
            // to avoid accessing negative stairs
            int jump = solve(n-i, height, k, dp) + abs(height[n] - height[n-i]);
            minSteps = min(minSteps, jump);
            // trying all possible ways to reach index n and getting the minimum cost of jump over all possibilities.
        }
    }
    
    return dp[n] = minSteps;
}

int main() {
    
    int N = 6;
    int n = N-1;
    int k = 3;
    vector<int> height{30,10,60,10,60,50};
    vector<int> dp(n+1, -1);
    int ans = solve(n,height,k, dp);
    cout << ans;
    return 0;
}
