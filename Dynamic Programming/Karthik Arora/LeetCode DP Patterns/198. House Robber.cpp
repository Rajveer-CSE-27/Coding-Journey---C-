class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n];

        if(n == 1) {
            return nums[0];
        }

        dp[0] = nums[0];
        dp[1] = nums[1];

        for(int i=2; i<n; i++) {
            int val = dp[i-2];
            if(i > 2) {
                val = max(val, dp[i-3]);
            }
            dp[i] = nums[i] + val;

        }
        return max(dp[n-1], dp[n-2]);
    }
};
