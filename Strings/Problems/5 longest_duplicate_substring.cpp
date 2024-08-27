// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://leetcode.com/problems/longest-duplicate-substring/

Binary search + rabin_karp
Harr waqt classical rabin karp hi mat likho. Kabhi kabhi usse milta julta question me puch sakte hai.

**/

class Solution {
public:

    vector<pair<long long, long long>> pow_p;
    vector<pair<long long, long long>> hash;
    const int mod = 1e9 + 9;
    const int mod2 = 1e9 + 13;
    // 2 hash functions liye hai kyuki 1 se paas nhi ho rahe the saare test cases

    string check(int len, string& s) {
        
        // bas check karo ki len size ki strings me se koi ek hash_val > 1 times aa rhi hai kya
        
        int n = s.length();

        map<pair<long long, long long>, int> hash_map;

        for(int i=0; i<=n-len; i++) {
            long long h1 = (hash[i + len].first + mod - hash[i].first) % mod;
            h1 = (h1 * pow_p[n - i - 1].first)%mod;
            long long h2 = (hash[i + len].second + mod2 - hash[i].second) % mod2;
            h2 = (h2 * pow_p[n - i - 1].second)%mod2;

            hash_map[{h1,h2}]++;
            if(hash_map[{h1,h2}] > 1) {
                return s.substr(i,len);
            }
        }
        return "";

    }

    string longestDupSubstring(string s) {
        
        // if a substring of size = x occurs >= 2 times then substrings of size : x-1, x-2, .... , 1 would definitely occur
        // hence we can apply binary search on size of substring because it has pattern of type :: 111111111000000000. And we need to find biggest valid size

        string ans = "";
        int n = s.length();
        int low = 1, high = n;

        // preprocessing
        pow_p.resize(n);
        hash.resize(n+1, {0,0});

        pow_p[0].first = 1;
        pow_p[0].second = 1;
        for(int i=1; i<pow_p.size(); i++) {
            pow_p[i].first = (pow_p[i-1].first * 31) % mod;
            pow_p[i].second = (pow_p[i-1].second * 29) % mod2;
        }

        for(int i=0; i<n; i++) {
            hash[i+1].first = (hash[i].first + (s[i] - 'a' + 1)*pow_p[i].first) % mod;
            hash[i+1].second = (hash[i].second + (s[i] - 'a' + 1)*pow_p[i].second) % mod2;
        } 

        while(low <= high) {
            int mid = (low + high)/2;
            string res = check(mid,s);

            if(res.empty()) {
                high = mid - 1;
            } else {
                ans = res;
                low = mid + 1;
            }
        }

        return ans;
    }
};
