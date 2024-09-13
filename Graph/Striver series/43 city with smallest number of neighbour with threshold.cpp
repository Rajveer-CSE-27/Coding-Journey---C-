// || जय जय जय बजरंग बली ||

#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=PwMVNSJ5SLI&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=43
https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=city-with-the-smallest-number-of-neighbors-at-a-threshold-distance

Floyd warshall lagana hai.
dhyan rahe isme edges undirected hai
**/

class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // floyd warshall
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
        
        for(int i=1; i<=n; i++) {
            dp[i][i] = 0;
        }
        
        for(int i=0; i<m; i++) {
            dp[edges[i][0] + 1][edges[i][1] + 1] = edges[i][2]; // 1 based here
            dp[edges[i][1] + 1][edges[i][0] + 1] = edges[i][2]; // for making undirected
        }
        
        // this is for directed
        for(int k=1; k<=n; k++) {
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=n; j++) {
                    if(dp[i][k] != INT_MAX and dp[k][j] != INT_MAX and dp[i][j] > dp[i][k] + dp[k][j]) {
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                }
            }
        }
        
        
        
        
        int cnt = n+1, ans = 0;
        
        for(int i=1; i<=n; i++) {
            int tempCnt = 0;
            for(int j=1; j<=n; j++) {

                if(i != j and dp[i][j] <= distanceThreshold) {
                    tempCnt++;
                }
            }
            
            if(tempCnt <= cnt) {
                ans = i-1; // 0 based indexing
                cnt = tempCnt;
            }
        }
        
        return ans;
    }
};


int main() {
        
    return 0;
}
