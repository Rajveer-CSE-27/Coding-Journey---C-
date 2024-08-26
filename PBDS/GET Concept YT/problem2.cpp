// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://leetcode.com/problems/create-sorted-array-through-instructions/

PBDS
    
    Go on filling oset from left to right
    keep comparator as less_equal
    At each time calculate strictly smaller values by oset function
    Also keep map of freq and by number of smaller values and map you can get number of strictly greater values.
    

**/

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int n = instructions.size();

        map<int,int> freq;
        oset o;
        o.insert(instructions[0]);
        freq[instructions[0]]++;

        int ans = 0;
        int mod = 1e9 + 7;
        for(int i=1; i<n; i++) {
            
            int smaller = o.order_of_key(instructions[i]);
            int bigger = i - smaller - freq[instructions[i]];

            int mn = min(smaller, bigger);

            ans = (ans%mod + mn%mod)%mod;
            freq[instructions[i]]++;
            o.insert(instructions[i]);

        }
        return ans;
    }
};
