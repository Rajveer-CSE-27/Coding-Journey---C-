/**
Problem Statement : Given an array of ‘N’  positive integers,
                    we need to return the maximum sum of the subsequence such that 
                    no two elements of the subsequence are adjacent elements in the array.
                    Note: A subsequence of an array is a list with elements of the array 
                          where some elements are deleted ( or not deleted at all) and 
                          the elements should be in the same order in the subsequence as in the array.
                    Note: All elements are non-negative.
                    
Approach : More space optimization from tabulation because we observe that to solve for an index we only need answers of previous index
          and (prev - 1)th index each time.

Time Complexity = nearly O(n) because for each index we will be computing answer only once which takes O(1) time
Space Complexity = O(1)

**/
#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& vc) {
    if(n == 1) {
        return vc[0];
    }
    int curr, prev = vc[0], prev2 = 0;
    // because initially we are at index 1 and for 1st index the prev is 0th index and prev2 is the negative index case which gives 0 result
    
    for(int i=1; i<n; i++) {
        int pick = vc[i] + prev2;
        int notPick = 0 + prev;
        curr = max(pick, notPick);
        prev2 = prev;
        prev = curr;
    }
    
    return curr;
}

int main() {
    vector<int> vc{2,1,4,9};
    int n = 4;
    
    int ans = solve(n,vc);
    cout << ans << "\n";
    return 0;
}
