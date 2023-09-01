/**
Problem Statement : This is a follow-up question to “Frog Jump”. 
                    In the previous question, the frog was allowed to jump either one or two steps at a time. 
                    In this question, the frog is allowed to jump up to ‘K’ steps at a time. 
                    If K=4, the frog can jump 1,2,3, or 4 steps at every index.

Approach :  We will be using recursion because we need to find minimum path out of all possible paths and jaha bhi all possible aya waha
           hum recursion try karenge.
           If we are at stair (i) : solve for (i-1), (i-2), (i-3), ...., (i-k) recursively then we need to check which path will be of min value :
           The path from i-1 to i or from i-2 to i or from i-3 to i ,......, from i-k to i.
           Recurrence relation : F(n) = F(n-1) + F(n-2) + F(n-3) + ... + F(n-k).


Time Complexity = O(K^n) because for each index we will be exploring 2 paths therefore total paths = k*k*k*...*k = k^n
Space Complexity = O(n) auxillary stack space,  because max depth of recursion will be n elements.

**/

#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& height, int k) {
    if(n == 0) {
        return 0;
        // base case
    }
    
    int minSteps = INT_MAX;
    
    for(int i=1; i<=k; i++) {
        if(n >= i) {
            // to avoid accessing negative stairs
            int jump = solve(n-i, height, k) + abs(height[n] - height[n-i]);
            minSteps = min(minSteps, jump);
            // trying all possible ways to reach index n and getting the minimum cost of jump over all possibilities.
        }
    }
    
    return minSteps;
}

int main() {
    
    int N = 6;
    int n = N-1;
    int k = 3;
    vector<int> height{30,10,60,10,60,50};
    
    int ans = solve(n,height,k);
    cout << ans;
    return 0;
}
