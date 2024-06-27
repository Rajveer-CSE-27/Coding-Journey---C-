class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[3][n];
        
        dp[0][0] = 0;
        dp[1][0] = -prices[0];
        dp[2][0] = 0;

        if(n == 1) {
            return 0;
        }

        dp[0][1] = max(dp[0][0], dp[1][0] + prices[1]);
        dp[1][1] = max(dp[1][0], dp[0][0] - prices[1]);
        dp[2][1] = 0;

        for(int i=2; i<n; i++) {
            int noStock = max({dp[0][i-1], dp[1][i-1] + prices[i], dp[2][i-1]});
            int stock = max(dp[1][i-1], dp[2][i-1] - prices[i]);
            int coolDown = max(dp[2][i-1], dp[1][i-2] + prices[i-1]);

            dp[0][i] = noStock;
            dp[1][i] = stock;
            dp[2][i] = coolDown;
        }

        return max({dp[0][n-1], dp[1][n-1], dp[2][n-1]});
    }
};
