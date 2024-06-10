class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 0;

        for(int i=2; i<=n; i++) {
            int val1 = dp[i-1] + cost[i-1];
            int val2 = dp[i-2] + cost[i-2];
            dp[i] = min(val1, val2);
        }
        return dp[n];
    }
};
