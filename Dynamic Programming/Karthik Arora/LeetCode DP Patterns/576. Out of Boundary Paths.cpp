class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int mod = 1e9 + 7;
        int dp[m][n][maxMove+1];
        memset(dp, 0, sizeof(dp));

        if(maxMove == 0) {
            return 0;
        }

        for(int i=0; i<m; i++) {
            dp[i][0][1]++;
            dp[i][n-1][1]++;
        }
        for(int j=0; j<n; j++) {
            dp[0][j][1]++;
            dp[m-1][j][1]++;
        }
        
        for(int move=2; move<=maxMove; move++) {
            for(int i=0; i<m; i++) {
                for(int j=0; j<n; j++) {
                    long long ans = dp[i][j][1]; // ye humesha lena bohot imp hai. Cause isse edge case ache se cover hote hai
                    if(i+1 < m) {
                        ans += dp[i+1][j][move-1];
                    }
                    if(j+1 < n) {
                        ans += dp[i][j+1][move-1];
                    }
                    if(i-1 >= 0) {
                        ans += dp[i-1][j][move-1];
                    }
                    if(j-1 >= 0) {
                        ans += dp[i][j-1][move-1];
                    }
                    dp[i][j][move] = ans%mod;
                }
            }
        }

        return dp[startRow][startColumn][maxMove];
    }
};
