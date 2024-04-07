#include <bits/stdc++.h>
using namespace std;
#define int long long

/**

Problem link :: https://codeforces.com/contest/439/problem/D

Approach :: The value would be from min of A and max of B. 
    We see unimodal function for the setting the value x such that all the elements in A will be converted to >= x and all the elements in B will be converted to <= x.
    
    Hence apply ternary search.

**/

int n,m;

vector<int> a,b;

int fun(int x) {
    int cost = 0;
    
    for(int i=0; i<n; i++) {
        if(a[i] < x) {
            cost += (x - a[i]);
        }
    }
    for(int i=0; i<m; i++) {
        if(b[i] > x) {
            cost += (b[i] - x);
        }
    }
    return cost;
}

signed main() {
    
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    
    int mnA = INT_MAX;
    int mxB = 0;
    
    for(int i=0; i<n; i++) {
        cin >> a[i];
        mnA = min(mnA, a[i]);
    }
    
    for(int i=0; i<m; i++) {
        cin >> b[i];
        mxB = max(mxB, b[i]);
    }
    
    int l = mnA, r = mxB;
    
    while(l < r) {
        int m1 = l + (r-l)/3;
        int m2 = r - (r-l)/3;
        
        int f1 = fun(m1), f2 = fun(m2);
        
        if(f1 > f2) {
            l = m1 + 1;
        } else if(f1 < f2) {
            r = m2 - 1;
        } else {
            l = m1 + 1;
            r = m2 - 1;
        }
    }
    cout << min(fun(l), fun(r));
    
    return 0;
}
