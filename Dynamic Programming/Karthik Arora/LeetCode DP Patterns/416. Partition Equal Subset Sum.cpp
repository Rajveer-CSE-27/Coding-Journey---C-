class Solution {
public:

    vector<vector<char>> dp;

    bool solve(int index, int sm, vector<int>& nums, int& n) {
        if(index == n) {
            return false;
        }
        if(sm == 0) {
            return true;
        }
        if(dp[index][sm] != '2') {
            if(dp[index][sm] == '1') {
                return true;
            }
            return false;
        }
        bool take = false, notTake = false;
        if(sm >= nums[index]) {
            take = solve(index+1, sm - nums[index], nums, n);
        }
        notTake = solve(index+1, sm, nums, n);

        bool ans = take or notTake;
        if(ans == true) {
            dp[index][sm] = '1';
        } else {
            dp[index][sm] = '0';
        }
        
        return ans;

    }

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
        dp.resize(n, vector<char>(sm + 1, '2'));

        return solve(0,sm,nums,n);
    }
};
