/**
https://leetcode.com/problems/burst-balloons/
**/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:


    int fun(int i, int j, vector<int>& vc, vector<vector<int>>& dp) {
        
        // i and j are begin and end multipliers
        
        if(i + 2 > j) {
            return 0;
        }
        
        if(i+2 == j) {
            return vc[i]*vc[i+1]*vc[i+2];
        }
        
        if(dp[i+1][j-1] != -1) {
            return dp[i+1][j-1];
        }
        
        int ans = -1;
        for(int k=i+1; k<=j-1; k++) {
            // bursting kth balloon at end
            
            int val = vc[i]*vc[k]*vc[j];
            
            val += fun(i,k,vc,dp) + fun(k,j,vc,dp);
            ans = max(ans, val);
        }
        
        return dp[i+1][j-1] = ans;
        
        
    }

    int maxCoins(int N, vector<int> &arr) {
        // code here
        
        vector<int> vc;
        vc.push_back(1);
        for(int i=0; i<N; i++) {
            vc.push_back(arr[i]);
        }
        vc.push_back(1);
        
        int n = vc.size();
        
        vector<vector<int>> dp(n, vector<int>(n,-1));
        
        int ans = fun(0, n-1, vc, dp);
        
        return ans;
        
    }
};
