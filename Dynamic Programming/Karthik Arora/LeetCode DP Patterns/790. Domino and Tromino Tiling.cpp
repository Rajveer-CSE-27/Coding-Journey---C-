class Solution {
public:
    int numTilings(int n) {
        int dp[1001];
        memset(dp,0,sizeof(dp));
        int mod = 1e9 + 7;

        dp[0] = 1; // just for edge case where top is type - 2 and bottom is also type 2
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        /** dp[n] = dp[n-1] + dp[n-2] + 2*(dp[n-3] + dp[n-4] + ... + dp[0])
            dp[n] = dp[n-1] + dp[n-2] + dp[n-3] + dp[n-3] + 2*(dp[n-4] + ..... + dp[0])
            dp[n] = dp[n-1] + dp[n-3] + dp[n-2] + dp[n-3] + 2*(dp[n-4] + ..... + dp[0])
            dp[n] = dp[n-1] + dp[n-3] + dp[n-1]
            dp[n] = 2*dp[n-1] + dp[n-3]
        **/


        for(int i=4; i<=n; i++) {
            long long temp = 2*dp[i-1];
            temp %= mod;
            temp = (temp + dp[i-3])%mod;
            dp[i] = temp;
            
        }
        return dp[n];
    }
};
