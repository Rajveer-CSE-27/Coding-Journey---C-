class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m));
        // dp[i][j] = side length of largest square ending at i,j cell. That is having bottom right corner at cell i,j

        // if matrix[i][j] == '0' then dp[i][j] = 0

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = 1;
                }
            }
        }


        // dp[i][j] will depend on dp[i-1][j-1]
        // cell i,j will extend the square ending at i-1,j-1 only if it contains some number of 1's above it and left to it

        /**
            1 1 1
            1 1 1 1
            1 1 1 1
              1 1 1 this last cell will now have val = 3;
        **/

        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(dp[i][j] == 1) {
                    if(dp[i-1][j-1] != 0) {
                        int val = dp[i-1][j-1];
                        int mx = 0;
                        int cnt1 = 0;
                        for(int up=i-1; up >= i-val; up--) {
                            if(matrix[up][j] == '0') {
                                break;
                            }
                            cnt1++;
                        }
                        int cnt2 = 0;
                        for(int left=j-1; left >= j-val; left--) {
                            if(matrix[i][left] == '0') {
                                break;
                            }
                            cnt2++;
                        }
                        int ans = min(cnt1,cnt2);
                        dp[i][j] = max(dp[i][j], ans+1);
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans = max(ans, dp[i][j]);
            }
        }

        // return side^2
        return ans*ans;
    }
};
