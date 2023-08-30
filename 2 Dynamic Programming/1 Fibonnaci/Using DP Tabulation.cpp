/** 
 Print nth Fibonnaci number
 Using DP Tabulation that is bottom to top approach.
 Approach :: Here we will be following an approach which will take us from base cases(bottom) to the 
             required nth case (top case). Here we will optimize on space by avoiding recursion and
             perform only iteration or tabulation
**/

/** 
    Time Complexity = O(n) , because we need to fill n addresses in the dp array which will take O(1) time each 
                            for fibonnaci problem.
                             
    Space Complexity = O(n) for dp array. And this is better than memoization.
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    vector<int> dp(n+1, -1); // because we will be requiring 0th fibonacci number also
    
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    cout << dp[n];
    
    // you just need to efficiently understand the recurrence relation from memoization 
    // and correctly convert to tabulation.
    
    return 0;
}
