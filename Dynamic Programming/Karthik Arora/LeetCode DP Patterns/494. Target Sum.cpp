class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(1001, 0);

        //tree banaoge to pata chalega positive and negative values same number of times aa rhi hai

        if(target < 0) {
            target *= -1;
        }

        dp[nums[0]] = 2;
        for(int i=1; i<n; i++) {
            vector<int> tempDp(1001, 0);
            for(int j=0; j<=1000; j++) {
                if(dp[j] != 0) {
                    int val = abs(j + nums[i]);
                    int val2 = abs(j - nums[i]);
                    tempDp[val] += dp[j];
                    tempDp[val2] += dp[j];
                }
            }
            dp = tempDp;
        }

        int ans = dp[target]/2;
        if(target == 0) { // edge case Isme 2 baar nhi ginte
            ans = dp[target];
        }
        return ans;
    }
};
