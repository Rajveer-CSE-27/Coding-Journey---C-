class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        int dp[n][m];
        memset(dp, -1, sizeof(dp));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
            }
        }
        bool flag = true;
        for(int i=0; i<n; i++) {
            if(obstacleGrid[i][0] == 1) {
                flag = false;
            }
            if(flag == true) {
                dp[i][0] = 1;
            } else {
                dp[i][0] = 0;
            }
        }
        flag = true;
        for(int j=0; j<m; j++) {
            if(obstacleGrid[0][j] == 1) {
                flag = false;
            }
            if(flag == true) {
                dp[0][j] = 1;
            } else {
                dp[0][j] = 0;
            }
        }
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(dp[i][j] == -1) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};
