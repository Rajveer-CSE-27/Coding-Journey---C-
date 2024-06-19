class Solution {
public:

    int dp[51][51];

    int fun(int i, int j, vector<int>& values) {
        if(i+1 == j) {
            return 0;
        }
        if(i+2 == j) {
            return values[i]*values[i+1]*values[i+2];
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = INT_MAX;
        for(int point = i+1; point < j; point++) {
            int val = values[i]*values[point]*values[j];
            val += fun(i, point, values) + fun(point, j, values);
            ans = min(ans, val); 
        }

        return dp[i][j] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

        // we are taking base = 0 and n-1 cause this base will be a base for exact 1 traingle becuase ::
            // observation 1 :: each side of polygon will be part of exactly 1 triangle. To meet the condition of n-2 triangles

        memset(dp, -1, sizeof(dp));
        // dp[i][j] = minimum score possible with vertices from i to j

        int ans = fun(0, n-1, values);
        return ans;

        
    }
};
