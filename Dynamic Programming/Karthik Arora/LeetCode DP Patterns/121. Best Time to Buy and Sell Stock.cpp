class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mnTillNow = INT_MAX;
        int n = prices.size();

        for(int i=0; i<n; i++) {
            // selling at ith day
            int sellPrice = prices[i];
            int profit = sellPrice - mnTillNow;
            ans = max(ans, profit);
            mnTillNow = min(mnTillNow, prices[i]);
        }
        return ans;
    }
};
