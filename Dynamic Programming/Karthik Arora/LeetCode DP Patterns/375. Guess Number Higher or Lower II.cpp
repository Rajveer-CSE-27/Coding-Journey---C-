class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // dp[i][j] will tell us minimum coins we need to carry to handle the segment [i,j]
        // dp[i][i] = 0; for all i

        // now we need to create 2d matrix and move diagonally
        // for dp[i][j] :: our guess will range from i to j

        for(int i=2; i<=n; i++) {
            int row = 1, col = i;
            while(col <= n) {
                int ans = INT_MAX;
                for(int t=row; t <= col; t++) {
                    // t is the guess
                    int val = t;
                    int add = -1;
                    // that is from current guess we see whether going right or left which one will take our coins more
                    if(t-1 >= row) {
                        // going left
                        add = max(add,dp[row][t-1]);
                    }
                    if(t+1 <= col) {
                        // going right
                        add = max(add, dp[t+1][col]);
                    }
                    val += add;

                    // hence will take minimum value as answer as we spend least coins
                    ans = min(ans,val);

                }
                dp[row][col] = ans;

                row++;
                col++;
            }
        }
        return dp[1][n];
    }
};
