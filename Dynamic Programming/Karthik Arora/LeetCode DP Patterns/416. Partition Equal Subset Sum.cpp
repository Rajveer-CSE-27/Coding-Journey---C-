class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sm = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            sm += nums[i];
        }

        if(sm&1) {
            return false;
        }
        sm /= 2;
        int dp[n][sm+1];

        for(int i=0; i<n; i++) {
            dp[i][0] = true;
        }
        for(int i=0; i<n; i++) {
            for(int j=1; j<=sm; j++) {
                if(i == 0) {
                    if(nums[i] == j) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = false;
                    }
                } else {
                    bool take = false;
                    if(j >= nums[i]) {
                        take = dp[i-1][j - nums[i]];
                    }
                    bool notTake = dp[i-1][j];
                    dp[i][j] = take or notTake;
                }
            }
        }
        return dp[n-1][sm];
    }
};
