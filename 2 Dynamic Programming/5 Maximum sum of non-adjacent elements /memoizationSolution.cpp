/**
Problem Statement : Given an array of ‘N’  positive integers,
                    we need to return the maximum sum of the subsequence such that 
                    no two elements of the subsequence are adjacent elements in the array.
                    Note: A subsequence of an array is a list with elements of the array 
                          where some elements are deleted ( or not deleted at all) and 
                          the elements should be in the same order in the subsequence as in the array.
                    Note: All elements are non-negative.
                    
Approach : We will apply memoization over the recursion solution to save the time. Because this problem has 
           overlapping subproblems.

Time Complexity = nearly O(n) because for each index we will be computing answer only once which takes O(1) time
Space Complexity = O(n) : space for storing answers of each index + O(n) : auxillary stack space.

**/
#include <bits/stdc++.h>
using namespace std;

int solve(int index, vector<int>& vc, vector<int>& dp) {
    if(index == 0) {
        // edge case if we are at first element then definitely it will be included in sum as 
        // all elements are >=0 in array
        dp[0] = vc[0];
        return vc[0];
    }
    
    if(index == -1) {
        // if we go beyond array then return 0 to sum
        return 0;
    }
    
    if(dp[index] != -1) {
        return dp[index];
    }
    
    int pick = vc[index] + solve(index - 2, vc, dp); // because no adjacent condition
    int notPick = 0 + solve(index - 1, vc, dp);
    
    return dp[index] = max(pick,notPick);
}

int main() {
    vector<int> vc{2,1,4,9};
    int n = 4;
    vector<int> dp(n, -1);
    
    int ans = solve(n-1, vc, dp);
    // we start from last element hence n-1
    cout << ans << "\n";
    return 0;
}
