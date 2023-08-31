/**
Problem Statement : Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. 
                    At a time the frog can climb either one or two steps. A height[N] array is also given. 
                    Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]).
                    We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.
                    
Approach : We will apply tabulation over the memoization solution to save the space.

Time Complexity = O(n) because for each index we will be computing answer only once
Space Complexity = O(n) : space for storing answers of each index.

**/

#include <bits/stdc++.h>
using namespace std;



int main() {
    int N = 6;
    int n = N-1;
    // 0 based indexing
    vector<int> height{30,10,60,10,60,50};
    vector<int> dp(N);
    
    dp[0] = 0;
    dp[1] = abs(height[1] - height[0]);
    // base cases of memoization
    
    for(int i=2; i<=n; i++) {
        dp[i] = min(dp[i-1] + abs(height[i] - height[i-1]), dp[i-2] + abs(height[i] - height[i-2]));
    }
    cout << dp[n];
    return 0;
}
