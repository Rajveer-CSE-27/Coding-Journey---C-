class Solution {
public:
    int houseRobber1(vector<int> nums) {
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

    int rob(vector<int>& nums) {
        // 2 cases of house robber 1
        // case 1 :: we do not include  last house. 
        // case 2 :: we do not include first house.



        vector<int> nums1, nums2;
        int n = nums.size();

        if(n == 1) {
            return nums[0];
        } 

        for(int i=0; i<n-1; i++) {
            nums1.push_back(nums[i]);
        }
        for(int i=1; i<n; i++) {
            nums2.push_back(nums[i]);
        }

        int ans1 = houseRobber1(nums1);
        int ans2 = houseRobber1(nums2);
        return max(ans1, ans2);

    }
};
