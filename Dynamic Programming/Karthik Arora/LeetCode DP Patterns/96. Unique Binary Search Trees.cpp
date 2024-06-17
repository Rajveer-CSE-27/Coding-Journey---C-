class Solution {
public:

    int dp[20];

    int numTrees(int n) {
        dp[0] = dp[1] = 1;
        dp[2] = 2;

        for(int i=3; i<=n; i++) {
            int res = 0;
            for(int left=0; left < i/2; left++) {
                res += 2 * (dp[left]*dp[i-left-1]);
            }
            if(i&1) {
                res += dp[i/2]*dp[i/2];
            }
            dp[i] = res;
        }
        return dp[n];
    }
};
