class Solution {
public:
    int knightDialer(int n) {
        vector<long long> dp(10, 1);
        int mod = 1e9 + 7;

        vector<long long> tempDp(10);
        for(int i=2; i<=n; i++) {
            tempDp[0] = (dp[4] + dp[6])%mod;
            tempDp[1] = (dp[6] + dp[8])%mod;
            tempDp[2] = (dp[7] + dp[9])%mod;
            tempDp[3] = (dp[4] + dp[8])%mod;
            tempDp[4] = ((dp[0] + dp[3])%mod + dp[9])%mod;
            tempDp[5] = 0;
            tempDp[6] = ((dp[0] + dp[1])%mod + dp[7])%mod;
            tempDp[7] = (dp[2] + dp[6])%mod;
            tempDp[8] = (dp[1] + dp[3])%mod;
            tempDp[9] = (dp[2] + dp[4])%mod;
            dp = tempDp;
        }

        long long ans = 0;
        for(int i=0; i<10; i++) {
            ans = (ans + dp[i])%mod;
        }
        return ans;
    }
};
