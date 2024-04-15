#include <bits/stdc++.h>
using namespace std;
#define int long long

/**
Problem link :: https://cses.fi/problemset/result/9018042/

Approach :: 
        Let us form a dp matrix of size n*n.
        dp[i][j] = stores a pair<x,y> ::
                            -> x = index of the most suitable pick between i, j
                            -> y = maximum possible sum from current segment [i to j] in the given array 
        
        base case ::
        for i==j there will be only 1 option to pick which is the ith value from the array.
        
        dp[i][j] = will help us to get the maximum possible sum if a player needs to make a choice in picking either element at ith or jth location in the array.
        
        dp[i][j] will have 2 choices :: 
                    if we pick the ith element then the next player will have choice between (i+1 or j) th index to choose.
                    if we pick the jth element then the next player will have choice between (i or j-1) th index to choose.
                    
                    We will pick the choice which will minimize the sum for other player.
                    Hence if dp[i+1][j] > dp[i][j-1] then we will pick  ith index. 
                    else if dp[i][j-1] > dp[i+1][j] then we will pick jth index.
                    else :: 
                            we will check whether x[i] or x[j] is bigger and pick that.
        
        At the end answer will be stored at dp[1][n] that is maximum sum possible if we have choice of choosing 1st or nth index. Becuase we are player 1.
        
        In each iteration we will move diagonally.
        Note :: we will only form the upper triangle of the matrix. You can check by forming.
**/

signed main() {
    
    int n;
    cin >> n;
    vector<int> x(n+1);
    for(int i=1; i<=n; i++) {
        cin >> x[i];
    }
    
    vector<int> pref(n+1);
    int sm = 0;
    pref[0] = 0;
    for(int i=1; i<=n; i++) {
        sm += x[i];
        pref[i] = sm;
    }
    
    vector<vector<pair<int,int>>> dp(n+1, vector<pair<int,int>>(n+1));
    
    // base cases. When low = high
    
    for(int i=1; i<=n; i++) {
        dp[i][i] = {i, x[i]};
    }
    
    for(int k=2; k<=n; k++) {
        
        int i=1, j=k;
        
        while(i <=n and j<= n) {
            pair<int,int> left = dp[i][j-1];
            pair<int,int> down = dp[i+1][j];
            
            // we will choose a value between i and j such that next value must be less for other player.
            
            int sum_of_segment = pref[j] - pref[i-1];
            int val1 = sum_of_segment - left.second;
            int val2 = sum_of_segment - down.second;
            
            if(val1 > val2) {
                dp[i][j] = {down.first, val1};
            } else if(val2 > val1) {
                dp[i][j] = {left.first, val2};
            } else {
                if(x[down.first] >= x[left.first]) {
                    dp[i][j] = {down.first, val1};
                } else {
                    dp[i][j] = {left.first, val1};
                }
            }
            i++;
            j++;
        }
    }
    
    
    cout << dp[1][n].second;
    
    return 0;
}
