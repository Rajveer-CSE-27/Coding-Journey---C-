/**
Problem Statement : Given an array of ‘N’  positive integers,
                    we need to return the maximum sum of the subsequence such that 
                    no two elements of the subsequence are adjacent elements in the array.
                    Note: A subsequence of an array is a list with elements of the array 
                          where some elements are deleted ( or not deleted at all) and 
                          the elements should be in the same order in the subsequence as in the array.
                    Note: All elements are non-negative.
                    
Approach : We will apply tabulation i.e bottom-up DP over the memoization solution to save space

Time Complexity = nearly O(n) because for each index we will be computing answer only once which takes O(1) time
Space Complexity = O(n) : space for storing answers of each index.

**/
#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<int> vc{2,1,4,9};
    int n = 4;
    vector<int> dp(n, 0);
    
    // edge case of memoization
    dp[0] = vc[0];
    
    for(int i=1; i<n; i++) {
        
        // int pick = vc[i] + dp[i-2]; this will give edge case if i == 1 then it will trigger dp[-1]
        int pick = vc[i];
        if(i > 1) {
            pick += dp[i-2];
        } else {
            pick += 0; // that was the case for negatives in memoization.
        }
        
        int notPick = 0 + dp[i-1];
        
        dp[i] = max(pick, notPick);
    }
    
    cout << dp[n-1] << "\n";
    return 0;
}
