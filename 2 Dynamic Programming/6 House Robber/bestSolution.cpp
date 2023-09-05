/**
Problem Statement : A thief needs to rob money in a street. The houses in the street are arranged in a circular manner. 
                    Therefore the first and the last house are adjacent to each other. 
                    The security system in the street is such that if adjacent houses are robbed, the police will get notified.

                    Given an array of integers “Arr” which represents money at each house, 
                    we need to return the maximum amount of money that the thief can rob without alerting the police.
                    Note: A subsequence of an array is a list with elements of the array 
                          where some elements are deleted ( or not deleted at all) and 
                          the elements should be in the same order in the subsequence as in the array.
                    Note: All elements are non-negative.
                    
Approach : Just a slight varition to previous problem.
           We would think many logics but we can do it with approach of previous problem itself.
           We see that house 1st and nth are adjacent to each other so they can never be in any subsequence together. This is the only 
           differentiation factor rest all is same.
           So we will compute 2 answers using previous problem code. 
                1. Compute answer for all elements excluding 1st
                2. Compute answer for all elements excluding nth element 
           And then return max of the 2 answers. We will get the required subsequence with max sum and no 2 adjacent elements together even first and last.

Time Complexity = nearly O(n) because for each index we will be computing answer only once which takes O(1) time
Space Complexity = O(1)

**/
#include <bits/stdc++.h>
using namespace std;

int solve2(vector<int> vc) {
    int n = vc.size();
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

int solve(int n, vector<int>& vc) {
    if(n == 1) {
        return vc[0];
        // ultimate edge case
    }
    
    vector<int> vc1 = vc, vc2 = vc;
    vc1.erase(vc1.begin());
    vc2.pop_back();
    
    int removeFirst = solve2(vc1);
    int removeLast = solve2(vc2);
    
    return max(removeFirst, removeLast);
}

int main() {
    vector<int> vc{2,1,4,9};
    int n = 4;
    
    int ans = solve(n, vc);
    cout << ans << "\n";
    return 0;
}
