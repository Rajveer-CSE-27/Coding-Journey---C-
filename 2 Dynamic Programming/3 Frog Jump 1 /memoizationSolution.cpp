/**
Problem Statement : Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. 
                    At a time the frog can climb either one or two steps. A height[N] array is also given. 
                    Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]).
                    We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.
                    
Approach : We will apply memoization over the recursion solution to save the time.

Time Complexity = O(n) because for each index we will be computing answer only once
Space Complexity = O(n) : space for storing answers of each index + O(n) : auxillary stack space.

**/

#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& height, vector<int>& dp) {
    if(n == 0) {
        dp[0] = 0;
        return dp[0];
    }
    
    if(n == 1) {
        dp[1] = abs(height[1] - height[0]);
        return dp[1];
    }
    
    if(dp[n] != -1) {
        return dp[n];
        //memoization
    }
    
    int oneBehind = solve(n-1,height,dp);
    int twoBehind = solve(n-2,height,dp);
    
    return dp[n] = min(oneBehind + abs(height[n] - height[n-1]), twoBehind + abs(height[n] - height[n-2]));
}

int main() {
    int N = 6;
    int n = N-1;
    // 0 based indexing
    vector<int> height{30,10,60,10,60,50};
    vector<int> dp(N, -1);
    
    int ans = solve(n,height,dp);
    cout << ans;
    
    return 0;
}
