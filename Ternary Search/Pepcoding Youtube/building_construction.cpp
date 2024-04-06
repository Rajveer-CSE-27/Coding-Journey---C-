#include <bits/stdc++.h>
using namespace std;
#define int long long

/**
    Problem Link :: https://www.spoj.com/problems/KOPC12A/
    
    Proving that the variable x : which tells the cost for a given value of K satisfies a unimodal function.
    
    Least possible k = 0. The values is high.
    Till a good value of x the cost decreases and then increases forever after that. Hence this is a unimodal function.
    
    Keep in mind that we are dealing with discrete values of cost(x) hence do m1 + 1 and m2 - 1.

**/

int fun(int n, vector<int>& heights, vector<int>& cost, int x) {
    
    int ans = 0;
    for(int i=0; i<n; i++) {
        int diff = abs(x - heights[i]);
        diff *= cost[i];
        ans += diff;
    }
    
    return ans;
}

void solve() {
    
    int n;
    cin >> n;
    vector<int> heights(n), cost(n);
    
    int mxHeight = 0;
    for(int i=0; i<n; i++) {
        cin >> heights[i];
        mxHeight = max(mxHeight, heights[i]);
    }
    for(int i=0; i<n; i++) {
        cin >> cost[i];
    }
    
    int l=0, r = mxHeight;
    
    // ternary search
    while(l < r) {
        int m1 = l + (r - l)/3;
        int m2 = r - (r - l)/3;
        
        int f1 = fun(n,heights,cost,m1), f2 = fun(n,heights,cost,m2);
        
        if(f1 > f2) {
            l = m1 + 1; // becuase of discrete values we need to increase or decrease by 1
        } else if(f1 < f2) {
            r = m2 - 1;
        } else {
            l = m1 + 1;
            r = m2 - 1;
        }
    }
    cout << fun(n,heights,cost,l);
    
}

signed main() {
    
    
    int t;
    cin >> t;
    while(t--) {
        solve();
        cout << '\n';
    }
    return 0;
}
