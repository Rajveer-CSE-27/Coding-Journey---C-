class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis_till(n);
        vector<int> cnt_lis(n);

        lis_till[0] = 1;
        cnt_lis[0] = 1;
        
        for(int i=1; i<n; i++) {
            int ans = 1;
            int cnt = 1;
            for(int j=i-1; j>=0; j--) {
                if(nums[j] < nums[i]) {
                    int val = lis_till[j] + 1;
                    if(val > ans) {
                        ans = val;
                        cnt = cnt_lis[j];
                    } else if(val == ans) {
                        cnt += cnt_lis[j];
                    }
                }
            }
            lis_till[i] = ans;
            cnt_lis[i] = cnt;
        }

        int mx = *max_element(lis_till.begin(), lis_till.end());
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(lis_till[i] == mx) {
                ans += cnt_lis[i];
            }
        } 
        return ans;
    }
};
