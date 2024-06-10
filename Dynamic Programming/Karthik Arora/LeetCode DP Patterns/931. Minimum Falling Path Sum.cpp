class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp(m);
        dp = matrix[n-1];

        for(int i=n-2; i>=0; i--) {
            vector<int> tempDp(m);
            for(int j=0; j<m; j++) {
                int dir1 = INT_MAX, dir2 = INT_MAX, dir3 = INT_MAX;
                if(j > 0) {
                    dir1 = dp[j-1];
                }
                dir2 = dp[j];

                if(j < m-1) {
                    dir3 = dp[j+1];
                }

                tempDp[j] = matrix[i][j] + min(dir1, min(dir2,dir3));

            }
            dp = tempDp;
        }

        int ans = INT_MAX;
        for(int j=0; j<m; j++) {
            ans = min(ans, dp[j]);
        }
        return ans;
    }
};
