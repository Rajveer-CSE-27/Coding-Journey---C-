/**
Problem Statement : Given an array of ‘N’  positive integers,
                    we need to return the maximum sum of the subsequence such that 
                    no two elements of the subsequence are adjacent elements in the array.
                    Note: A subsequence of an array is a list with elements of the array 
                          where some elements are deleted ( or not deleted at all) and 
                          the elements should be in the same order in the subsequence as in the array.
                    Note: All elements are non-negative.
                    
Approach : First thing comes to mind is that we use recursion and identify all possible correct subsequences and get maximum
           sum out of all possible sums. We tend to use pick/not pick method to get subsequences and keep in mind
           we cannot place 2 adjacent elements in one subsequence.

Time Complexity = nearly O(2^n) because for each index we will be exploring 2 paths therefore total paths = 2*2*2.....*2 = 2^n
Space Complexity = O(n) : auxillary stack space.

**/
#include <bits/stdc++.h>
using namespace std;

int solve(int index, vector<int>& vc) {
    if(index == 0) {
        // edge case if we are at first element then definitely it will be included in sum as 
        // all elements are >=0 in array
        return vc[0];
    }
    
    if(index == -1) {
        // if we go beyond array then return 0 to sum
        return 0;
    }
    
    int pick = vc[index] + solve(index - 2, vc); // because no adjacent condition
    int notPick = 0 + solve(index - 1, vc);
    
    return max(pick,notPick);
}

int main() {
    vector<int> vc{2,1,4,9};
    int n = 4;
    
    int ans = solve(n-1, vc);
    // we start from last element hence n-1
    cout << ans << "\n";
    return 0;
}
