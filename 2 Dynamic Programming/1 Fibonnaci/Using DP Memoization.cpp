/** 
 Print nth Fibonnaci number
 Using DP Memoization that is top to bottom approach.
 Approach :: Just do like recursion because we are doing top bottom approach
             that is reaching base case from nth case and mantain additional 
             memory space to store results of overlapping subproblems
**/

/** 
    Time Complexity = O(n) , because if we draw the recursion tree we see that depth is maximum
                             n units. That is we need to fill for n places only and rest all will 
                             be taken care by dp vector in O(1) time.
                             
    Space Complexity = O(n) for recursion stack space + O(n) for dp array = O(2*n).
**/

#include <bits/stdc++.h>
using namespace std;

int fib(int n, vector<int>& dp) {
    if(n <= 1) {
        dp[n] = n;
        return n;
    }
    
    if(dp[n] != -1) {
        return dp[n];
        // here we avoided calculating overlapping subproblem again.
    }
    
    return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}


int main() {
    
    int n;
    cin >> n;
    vector<int> dp(n+1, -1); // because we will be requiring 0th fibonacci number also
    
    // printing nth Fibonnaci number
    int ans = fib(n, dp);
    cout << ans;
    
    
    return 0;
}
