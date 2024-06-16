class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<pair<int,int>>> dp1(n, vector<pair<int,int>>(2));
        vector<vector<pair<int,int>>> dp2(n, vector<pair<int,int>>(2));

        // dp1[i][0] ::  {minimum number of swaps needed till now to make array 1 increasing such that we will not perform a swap in ith iteration. , last value for next iteration}
        // dp1[i][1]  :: {minimum number of swaps needed till now to make array 1 increasing such that we will perform a swap in ith iteration, last value for next iteration}


        dp1[0][0] = {0,nums1[0]};
        dp1[0][1] = {1, nums2[0]};
        dp2[0][0] = {0, nums2[0]};
        dp2[0][1] = {1, nums1[0]};

        for(int i=1; i<n; i++) {
            int ans = INT_MAX;
            int next0, next1;

            // swap
            if(nums2[i] > dp1[i-1][0].second and nums1[i] > dp2[i-1][0].second) {
                int val = dp1[i-1][0].first + 1; // adding 1 becuase we perform a swap
                if(val < ans) {
                    ans = val;
                    next0 = nums2[i];
                    next1 = nums1[i];
                }
            }
            if(nums2[i] > dp1[i-1][1].second and nums1[i] > dp2[i-1][1].second) {
                int val = dp1[i-1][1].first + 1;// adding 1 becuase we perform a swap
                if(val < ans) {
                    ans = val;
                    next0 = nums2[i];
                    next1 = nums1[i];
                }
            }
            dp1[i][1] = {ans, next0};
            dp2[i][1] = {ans, next1};


            // no swap
            ans = INT_MAX;
            if(nums1[i] > dp1[i-1][0].second and nums2[i] > dp2[i-1][0].second) {
                int val = dp1[i-1][0].first;
                if(val < ans) {
                    ans = val;
                    next0 = nums1[i];
                    next1 = nums2[i];
                }
            }
            if(nums1[i] > dp1[i-1][1].second and nums2[i] > dp2[i-1][1].second) {
                int val = dp1[i-1][1].first;
                if(val < ans) {
                    ans = val;
                    next0 = nums1[i];
                    next1 = nums2[i];
                }
            }
            dp1[i][0] = {ans, next0};
            dp2[i][0] = {ans, next1};
        }

        return min({dp1[n-1][0].first, dp1[n-1][1].first});

    }
};
