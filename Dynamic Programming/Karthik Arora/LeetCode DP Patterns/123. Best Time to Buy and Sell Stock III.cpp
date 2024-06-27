class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int dp[n][3][2];
        // dp[i][j][k] : i = index , j = transaction number, k = havve stock or not

        memset(dp, 0, sizeof(dp));

        dp[0][0][1] = -prices[0];

        for(int i=1; i<n; i++) {

            dp[i][0][0] = dp[i-1][0][0];
            dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][0][0] - prices[i]);

            if(i == 1) {
                dp[i][1][0] = dp[i-1][0][1] + prices[i];
            } else if(i == 2) {
                dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][0][1] + prices[i]);
                dp[i][1][1] = dp[i-1][1][0] - prices[i];
            } else if(i == 3) {
                dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][0][1] + prices[i]);
                dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][1][0] - prices[i]);
                dp[i][2][0] = dp[i-1][1][1] + prices[i];
            } else {
                dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][0][1] + prices[i]);
                dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][1][0] - prices[i]);
                dp[i][2][0] = max(dp[i-1][2][0], dp[i-1][1][1] + prices[i]);
            }
        }
        int ans = 0;
        ans = max({ans, dp[n-1][2][0], dp[n-1][1][0], dp[n-1][0][0]});

        return ans;
    
    }
};
