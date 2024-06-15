class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9 + 7;
        vector<long long> dp(1001, 0);
        for(int i=1; i<=k; i++) {
            dp[i] = 1;
        }

        for(int i=1; i<n; i++) {
            vector<long long> tempDp(1001, 0);
            for(int j=1; j<=1000; j++) {
                if(dp[j] != 0) {
                    for(int l=1; l<=k; l++) {
                        if(j + l <= 1000) {
                            tempDp[j+l] = (tempDp[j+l] + dp[j])%mod;
                        }
                    }
                }
            }
            dp = tempDp;
        }
        return dp[target];
    }
};
