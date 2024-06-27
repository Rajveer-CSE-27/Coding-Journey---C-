class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int dp[2][n];

        // dp[1][i] = maximum profit that can be achieved if we have a stock at ith index
        // dp[0][i] = maximum profit that can be achieved if we do not have a stock at ith index.
        // at any point either we can have stock or cannot have stock.

        dp[0][0] = 0;
        dp[1][0] = -1*(prices[0] + fee);

        for(int i=1; i<n; i++) {
            int noStock = max(dp[0][i-1], prices[i] + dp[1][i-1]);
            int stock = max(dp[0][i-1] - (prices[i] + fee), dp[1][i-1]);

            dp[0][i] = noStock;
            dp[1][i] = stock;
        }

        return max({0,dp[0][n-1], dp[1][n-1]});
    }
};
