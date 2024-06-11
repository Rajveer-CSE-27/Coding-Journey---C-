/** dp[n][m]

  dp[i][j] will tell minimum energy required at that cell to move further.
  At any cell we must require minimum 1 energy to move further hence dp[n-1][m-1] = 1;

  Now from any cell we can either go to right :: [i][j+1] or down :: [i+1][j];
  If we go from [i][j] to [i+1][j] then minimum energy required at [i][j] = minimum energy required at [i+1][j] - dungeon[i][j]
                                                                            Becuase if dungeon[i][j] < 0 then we require more energy becuase going there will decrease our energy
                                                                                    else  we require less energy to go there because going there will increase our energy
                                                                            Note ;; energy required at any point is atleast 1.


Hence dp[i][j] = minimum energy required to move further right or down.
Final answer = max(1,dp[0][0] - dungeon[0][0])
Because we need to start with certain energy. 

Time :: O(n*m)
Space :: O(n*m)
**/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();

        int dp[n][m];
        // dp[i][j] = minimum energy required at cell (i,j)
        dp[n-1][m-1] = 1;

        for(int i=n-2; i>=0; i--) {
            dp[i][m-1] = max(1, dp[i+1][m-1] - dungeon[i+1][m-1]);
        }
        for(int j=m-2; j>=0; j--) {
            dp[n-1][j] = max(1, dp[n-1][j+1] - dungeon[n-1][j+1]);
        }

        for(int i=n-2; i>=0; i--) {
            for(int j=m-2; j>=0; j--) {
                int val1 = max(1, dp[i+1][j] - dungeon[i+1][j]);
                int val2 = max(1, dp[i][j+1] - dungeon[i][j+1]);
                dp[i][j] = min(val1, val2);
            }
        }
        int ans = max(1, dp[0][0] - dungeon[0][0]);
        return ans;
    }
};
