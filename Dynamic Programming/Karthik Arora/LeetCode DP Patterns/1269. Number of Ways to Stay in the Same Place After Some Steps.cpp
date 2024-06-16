class Solution {
public:
    int numWays(int steps, int arrLen) {
        
        vector<long long> dp(arrLen, 0);
        dp[0] = 1;
        int mod = 1e9 + 7;

        for(int l=1; l<=steps; l++) {
            vector<long long> tempDp(arrLen, 0);

            for(int i=0; i<min(arrLen, l+1) /** <--FOR TLE **/; i++) {
                tempDp[i] = (tempDp[i] + dp[i])%mod;
                if(i-1 >= 0) {
                    tempDp[i-1] = (tempDp[i-1] + dp[i])%mod;
                }
                if(i+1 < arrLen) {
                    tempDp[i+1] = (tempDp[i+1] + dp[i])%mod;
                }
                
            }
            dp = tempDp;
        }
        return dp[0];

    }
};
