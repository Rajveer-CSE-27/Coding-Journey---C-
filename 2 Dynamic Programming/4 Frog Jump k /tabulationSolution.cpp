/**
Problem Statement : This is a follow-up question to “Frog Jump”. 
                    In the previous question, the frog was allowed to jump either one or two steps at a time. 
                    In this question, the frog is allowed to jump up to ‘K’ steps at a time. 
                    If K=4, the frog can jump 1,2,3, or 4 steps at every index.

Approach :  We will apply tabulation over the memoization solution to save the space.


Time Complexity = O(n * k) because for each index we will be iterating to all possible k previous indices to get minimum jump.
Space Complexity = O(n) : space for storing answers of each index.

**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    
    int N = 6;
    int n = N-1;
    int k = 3;
    vector<int> height{30,10,60,10,60,50};
    vector<int> dp(n+1, -1);
    
    dp[0] = 0;
    for(int i=1; i<=n; i++) {
        
        int minSteps = INT_MAX;
        for(int j=1; j<=k; j++) {
            
            if(i-j >= 0) { // to avoid going to negative indexes
                int jump = dp[i-j] + abs(height[i] - height[i-j]);
                minSteps = min(minSteps, jump);
            }
        }
        dp[i] = minSteps; // giving correct value to ith stair.
    }
    
    cout << dp[n];
    
    return 0;
}
