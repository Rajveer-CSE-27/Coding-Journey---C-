class Solution {
public:

    int dp[1001][1001];

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, 0, sizeof(dp));
        int n = text1.length(), m = text2.length();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(text1[i] == text2[j]) {
                    int val = 1 + dp[i][j];
                    dp[i+1][j+1] = val;
                } else {
                    int val = max({dp[i][j+1], dp[i+1][j], dp[i][j]});
                    dp[i+1][j+1] = val;
                }
            }
        }
        return dp[n][m];
    }
};
