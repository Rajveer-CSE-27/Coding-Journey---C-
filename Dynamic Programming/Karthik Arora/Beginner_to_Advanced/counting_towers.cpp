#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**  
 transitions :
 
    //              _  _    _  _    _  _    _  _     _ _
    //  _  _       | || |  |_|| |  | ||_|  |_||_|   |_ _|
    // | || | =>   | || |, | || |, | || |, | || |,  | | |
    //              _ _    _ _    _ _ 
    //  _ _        |   |  |_|_|  |_ _|
    // |   |  =>   |   |, |   |, |   |
                  
**/


int main() {
    
    int N = 1e6;
    
    ll dp[N + 2][2];
    // dp[i][0] = number of ways to form structure from ith row to nth row such that there is 1 block of width = 2 at ith row.
    // dp[i][1] = number of ways to form structure from ith row to nth row such that there are 2 blocks of width = 1 at ith row.
    
    // base case 
    dp[1][0] = dp[1][1] = 1;
    // number of ways to form structure from 1st th row to 1st row = 1. for each width type.
    
    for(int i=2; i<=N; i++) {
        /** calculating dp[i][0] : if there is a block of width = 2 at ith row then 
                                                    -> we could have extended that block from previous block of width = 2 at height (i-1).
                                                    -> we have not extend this block from prev height.
                                        
                                        -> if we extend then dp[i][0] = dp[i-1][0] because at height i-1 there will also be a block of width = 2.
                                        -> if we not extend then dp[i][0] = dp[i-1][0] + dp[i-1][1] becuase we can either have a block of width = 2 or 2  blocks of width = 2 at height (i-1).
                                    
                                    Hence dp[i][0] will be result of adding all these cases results.
        **/
        ll op1 = dp[i-1][0];
        ll op2 = (dp[i-1][0] + dp[i-1][1])%mod;
        dp[i][0] = (op1 + op2)%mod;
        
        /** calculating dp[i][1] : If there are 2 blocks of width = 1 at ith row then 
                                                    -> we could have extended none of the two blocks from prev height (i-1).
                                                    -> we could have extended both.
                                                    -> we could have extended one of them.
                                        
                                        -> extending none then dp[i][1] = dp[i-1][0] + dp[i-1][1] becuase we can either have a block of width = 2 or 2 new blocks of width = 2 at height (i-1).
                                        -> extending both then dp[i][1] = dp[i-1][1] because we must have 2 blocks of widht = 1 at height (i-1).
                                        -> extending one :: either we extend left or right . Hence dp[i][1] = 2*(dp[i-1][1]) :: there must be 2 blocks of width = 1 at height (i-1) to extend one of them.
                                    
                                    Hence dp[i][1] will be result of adding all these cases results.
        **/
        ll op3 = dp[i-1][1];
        ll op4 = (2 * dp[i-1][1])%mod;
        dp[i][1] = (op2 + op3 + op4)%mod;
        
    }
    
    
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        
        ll ans = (dp[n][0] + dp[n][1])%mod;
        cout << ans << '\n';
    }
    
     
    return 0;
}
