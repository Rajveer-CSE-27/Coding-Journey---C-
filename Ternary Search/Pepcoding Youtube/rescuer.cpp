#include <bits/stdc++.h>
using namespace std;
#define ld long double

/**
Problem Link :: https://www.hackerearth.com/problem/algorithm/rescuer-2d2495cb/

Approach :: 
    Because v1 and v2 can be anything we cannot tell at which point (x,0) we will make contact to y=0 such that time is minimum
    But we see the total time is unimodal function if we go from extreme left x to extreme right x.
    
    Hence ternary search.
**/



ld fun(ld x, ld x1, ld x2, ld y1, ld y2, ld v1, ld v2) {
    
    ld dist1 = sqrt((x1 - x)*(x1 - x) + ((y1) * (y1)));
    ld dist2 = sqrt((x2 - x)*(x2 - x) + ((y2) * (y2)));
    
    ld time = dist1/v1;
    time += dist2/v2;
    
    return time; 
}

void solve() {
    
    ld x1,x2,y1,y2,v1,v2;
    cin >> x1 >> y1 >> x2 >> y2 >> v1 >> v2;
    
    ld l = -1e9;
    ld r = 1e9;
    
    while(r - l > 1e-7) {
        ld m1 = l + (r-l)/3;
        ld m2 = r - (r-l)/3;
        ld f1 = fun(m1,x1,x2,y1,y2,v1,v2), f2 = fun(m2,x1,x2,y1,y2,v1,v2);
        
        if(f1 > f2) {
            l = m1;
        } else if(f1 < f2) {
            r = m2;
        } else {
            l = m1;
            r = m2;
        }
    }
    
    cout << fixed << setprecision(5) << fun(l,x1,x2,y1,y2,v1,v2);
}

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        
        solve();
        cout << '\n';
    }
    
    return 0;
}
