// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=a8NxgMSJ-Lc&list=PLViazNtheeIMTme3nrdLesrvWSD-WBdk-&index=6
https://leetcode.com/problems/count-of-range-sum/description/
**/

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> oset;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long prefixSm = 0;
        oset o;
        o.insert(0); // to handle i==j case
        int cnt = 0;

        for(int j=0; j<n; j++) {
            // we want to find all valid i <= j for current j
            prefixSm += nums[j];

            /** for any valid i ::
                     l <= pref[j] - pref[i-1] <= u
                     l - pref[j] <= -pref[i-1] <= u - pref[j]
                     pref[j] - l >= pref[i-1] >= pref[j] - u
            **/
            int tempCnt1 = o.order_of_key(prefixSm - lower + 1ll);
            int tempCnt2 = o.order_of_key(prefixSm - upper);
            cnt += (tempCnt1 - tempCnt2);
            o.insert(prefixSm);
        }
        return cnt;
    }
};
