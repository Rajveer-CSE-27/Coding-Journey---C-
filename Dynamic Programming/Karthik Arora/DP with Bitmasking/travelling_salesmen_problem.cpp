// || जय जय जय बजरंग बली ||

//https://www.youtube.com/watch?v=QukpHtZMAtM&list=PLb3g_Z8nEv1icFNrtZqByO1CrWVHLlO5g&index=4

/**
Given a list of cities and the distances between each pair of cities,
what is the shortest possible route that visits each city and returns to the origin city.

You are given origin city as 1.
Constraints ::
number of cities <= 30.


Time Complexity :: O(n*n*(2^n))
Space :: O(n*(2^n))

**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> matrix;
vector<vector<int>> dp; 

int fun(int city, int subset, int& n) {
    
    if(subset == 0) {
        // then we need to return to city 1
        return matrix[city][1];
    }
    if(dp[city][subset] != -1) {
        return dp[city][subset];
    }
    
    // from current city we can go to any of the remaining city in the subset
    
    int ans = INT_MAX;
    for(int bit_no = 0; bit_no < n; bit_no++) {
        
        if(subset & (1<<bit_no)) {
            int val = matrix[city][bit_no + 1];
            int nextSubset = (subset ^ (1<<bit_no));
            val += fun(bit_no + 1, nextSubset, n);
            
            ans = min(ans, val);
        }
    }
    
    return dp[city][subset] = ans;
    
}

int main() {
    
    int n;
    cin >> n;
    matrix.resize(n+1, vector<int>(n+1));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // note that matrix[i][j] and matrix[j][i] could be different
    
    
    // currenlty we are at city 1 and we can visit any city {2,3,4,....n}
    int bitmask = (1<<n) - 2; // because we exclude city 1
    dp.resize(n+1, vector<int>((bitmask + 1), -1));
    
    int ans = fun(1, bitmask, n);
    cout << ans;
    
    return 0;
}
