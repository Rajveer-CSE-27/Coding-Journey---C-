// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

/**
https://www.cses.fi/problemset/task/2181

**/
int dp[1001][1<<11];

void generateNextMask(int mask, int bit_no, int n, int nextMask, vector<int>& next_col_masks) {
    
    if(bit_no == n) {
        next_col_masks.push_back(nextMask);
        return;
    }
    
    if(mask & (1<<bit_no)) {
        // current bit is filled hence do nothing to next mask
        generateNextMask(mask, bit_no + 1, n, nextMask, next_col_masks);
    }
    
    if((mask & (1<<bit_no)) == 0) {
        
        // filling 1*2 tile here
        generateNextMask(mask, bit_no + 1, n, nextMask ^ (1<<bit_no), next_col_masks);
        
        if(bit_no < n-1) {
            if((mask & (1<<(bit_no + 1))) == 0) {
                // filling 2*1 tile here hence wont change next mask
                generateNextMask(mask, bit_no + 2, n, nextMask, next_col_masks);
            }
        }
    }
}

int fun(int col, int mask, int n, int m) {
    
    if(col == m+1) {
        if(mask == 0) {
            return 1;
        }
        return 0;
    }
    
    if(dp[col][mask] != -1) {
        return dp[col][mask];
    }
    
    int ans = 0;
    
    vector<int> next_col_masks;
    generateNextMask(mask, 0, n, 0, next_col_masks);
    
    for(int b:next_col_masks) {
        ans = (ans + fun(col + 1, b, n, m))%mod;
    }
    
    return dp[col][mask] = ans;
    
}

signed main() {
    
    int n,m;
    cin >> n >> m;
    
    memset(dp, -1, sizeof(dp));
    //dp[i][j] = number of possible ways such that ith col is currently filled with bits that are active in j or has mask = j.
    
    int ans = fun(1, 0, n, m);
    cout << ans;
    
    return 0;
}
