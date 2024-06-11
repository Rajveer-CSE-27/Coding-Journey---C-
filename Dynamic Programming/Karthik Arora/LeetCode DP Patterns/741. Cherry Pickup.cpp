class Solution {
public:

    // think that both are starting from same postion and want to go to n,n together.
    // as both will travel either right or down in each step hence at any time both will take same steps; r1 + c1 = r2 + c2
    // dp[r1][c1][c2] will tell maximum number of cherries robots can get if they are at r1,c1 and r2,c2

    vector<vector<vector<int>>> dp;
    vector<vector<int>> matrix;
    int n;
    int fun(int r1, int c1, int c2) {

        int r2 = r1 + c1 - c2;
        // because both move same steps

        if(r1 == n or r2 == n or c1 == n or c2 == n) {
            return -1e9;
        }
        if(matrix[r1][c1] == -1 or matrix[r2][c2] == -1) {
            return -1e9;
        }

        if(r1 == n-1 and c1 == n-1) {
            return matrix[n-1][n-1];
            // because both will be at n-1,n-1
        }
        if(dp[r1][c1][c2] != -1e9) {
            return dp[r1][c1][c2];
        }

        int ans = matrix[r1][c1];
        if(r1 != r2 and c1 != c2) {
            ans += matrix[r2][c2];
            // if r1==r2 and c1==c2 we count that cherry only once
        }
        int down_down = fun(r1+1,c1,c2);
        int right_right = fun(r1, c1+1, c2+1);
        int right_down = fun(r1, c1+1, c2);
        int down_right = fun(r1+1, c1, c2+1);
        ans += max({down_down, right_right,right_down,down_right});
        return dp[r1][c1][c2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        matrix = grid;
        dp.resize(n, vector<vector<int>>(n, vector<int>(n, -1e9)));
        
        int ans = max(0, fun(0,0,0));
        return ans;
    }
};
