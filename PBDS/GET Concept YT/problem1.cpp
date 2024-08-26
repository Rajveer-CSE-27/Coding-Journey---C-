// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://leetcode.com/problems/number-of-pairs-satisfying-inequality/description/
Approach :: PBDS

Here we want pairs (i,j) with i < j
Rearrange the condition as :: nums1[i] - nums2[i] <= nums1[j] - nums2[j] + diff

use less_equal as it may contain duplicates
Start from the last index of array and go on removing it.
By removing from back we ensure that we only take i which are < current j.

**/

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> oset;


class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        oset o;

        for(int i=0; i<n; i++) {
            o.insert(nums1[i] - nums2[i]);
        }
        
        long long ans = 0ll;
        
        for(int i=n-1; i>0; i--) {
            int toRemove = nums1[i] - nums2[i];

            int index = o.order_of_key(toRemove);
            auto it = o.find_by_order(index);
            o.erase(it);

            int temp = o.order_of_key(toRemove + diff + 1); // adding 1 as inequality constains <= and order_of_key gives strictly <
            ans += (long long)temp;

        }
        return ans;
        
    }
};
