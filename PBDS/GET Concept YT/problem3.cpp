// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://leetcode.com/problems/reverse-pairs/

PBDS

comparator = greater_equal as we want to find strictly greater elements with duplicates
update data type to long long

start from back and go on removing to find valid i<j pairs.
**/

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<long long, null_type, greater_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> oset;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        oset o;

        for(int i=0; i<n; i++) {
            o.insert(nums[i]);
        }

        long long ans = 0;
        for(int i=n-1; i>0; i--) {
            // delete the current element {the rightmost element}

            int index = o.order_of_key(nums[i]);
            auto it = o.find_by_order(index);
            o.erase(it);

            // now find the required thing

            long long temp = o.order_of_key(2ll * nums[i]);
            ans += temp;
        }
        return ans;
    }
};
