#include <bits/stdc++.h>
using namespace std;
#define int long long

/**
Problem link :: https://codeforces.com/contest/1355/problem/E

    Approach :: Ternary search for finding min
    
    It can be seen that this is unimodal function. Hence ternary search.
    Only 1 condition needs to be checked while calculating cost whether adding + removing is costlier than moving or not.
**/

int fun(int n, int a, int r, int m, vector<int>& heights, int x) {
    
    vector<int> req(n);
    for(int i=0; i<n; i++) {
        req[i] = x - heights[i];
    }
    
    int cost = 0;
    if(a+r <= m) {
        for(int i=0; i<n; i++) {
            if(req[i] > 0) {
                cost += (a * req[i]);
            } else {
                cost += (r * (-req[i]));
            }
        }
        
    } else {
        int add = 0, remove = 0;
        for(int i=0; i<n; i++) {
            if(req[i] > 0) {
                add += req[i];
            } else {
                remove += (-req[i]);
            }
        }
        if(add >= remove) {
            cost += (m * remove);
            add -= remove;
            cost += (a * add);
        } else {
            cost += (m * add);
            remove -= add;
            cost += (r * remove);
        }
    }
    
    return cost;
}

signed main() {
    
    int n,add,remove,move;
    cin >> n >> add >> remove >> move;
    
    vector<int> heights(n);
    int mxHeight = 0;
    
    for(int i=0; i<n; i++) {
        cin >> heights[i];
        mxHeight = max(mxHeight, heights[i]);
    }
    
    int l = 0, r = mxHeight;
    
    //ternary search
    while(l < r) {
        int m1 = l + (r - l)/3;
        int m2 = r - (r - l)/3;
        
        int f1 = fun(n,add,remove,move,heights,m1), f2 = fun(n,add,remove,move,heights,m2);
        if(f1 > f2) {
            l = m1 + 1;
        } else if(f1 < f2) {
            r = m2 - 1;
        } else {
            l = m1 + 1;
            r = m2 - 1;
        }
    }
    cout << fun(n,add,remove,move,heights,l);
}
