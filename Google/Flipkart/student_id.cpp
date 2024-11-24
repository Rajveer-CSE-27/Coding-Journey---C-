#include <bits/stdc++.h>
using namespace std;
#define ll long long

 
class Solution {
public:

    bool check(vector<int>& temp1, vector<int>& temp2, int i, int j) {
        int m = temp1.size();
        int n = temp2.size();

        while(i < m and j < n) {
            if(temp1[i] > temp2[j]) {
                return true;
            }
            if(temp1[i] < temp2[j]) {
                return false;
            }
            i++;
            j++;
        }

        if(i != m) {
            return true;
        }
        return false;
    }

    vector<int> fun(vector<int>& vc, int x) {
        int n = vc.size();
        vector<int> res;

        for(int i=0; i<n; i++) {
            while(!res.empty() and res.back() < vc[i] and res.size() + n - i - 1 >= x) {
                res.pop_back();
            }

            if(res.size() < x) {
                res.push_back(vc[i]);
            }
        }

        return res;
    }

    vector<int> mix(vector<int>& temp1, vector<int>& temp2) {
        vector<int> res;
        int i = 0, j = 0;
        int m = temp1.size(), n = temp2.size();

        while(i < m and j < n) {
            if(temp1[i] > temp2[j]) {
                res.push_back(temp1[i]);
                i++;
            } else if(temp1[i] < temp2[j]) {
                res.push_back(temp2[j]);
                j++;
            } else {
                if(check(temp1, temp2, i, j) == true) {
                    res.push_back(temp1[i]);
                    i++;
                } else {
                    res.push_back(temp2[j]);
                    j++;
                }
            }
        }

        while(i < m) {
            res.push_back(temp1[i]);
            i++;
        }
        while(j < n) {
            res.push_back(temp2[j]);
            j++;
        }

        return res;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k, 0);

        int m = nums1.size(), n = nums2.size();
        int start = max(0, k - n);
        int endd = min(k, m);

        for(int i=start; i<=endd; i++) {
            if(i > m or k-i > n) {
                continue;
            }

            vector<int> temp1 = fun(nums1, i);
            vector<int> temp2 = fun(nums2, k - i);
            vector<int> together = mix(temp1, temp2);

            if(check(together, res, 0, 0) == true) {
                res = together;
            }
        }

        return res;
    }
};
