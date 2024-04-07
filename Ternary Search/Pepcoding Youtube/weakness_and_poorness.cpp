#include <bits/stdc++.h>
using namespace std;
#define ld long double

/**

Problem link :: https://codeforces.com/contest/578/problem/C

Approach :: Ternary search.

IMP note :: here jitna kum epsilon rakhoge utna better answer aega.
\
**/

int n;
vector<ld> vc;

ld kadane(vector<ld>& temp, int n) {
    
    ld max_so_far = LLONG_MIN, max_ending_here = 0, start = 0, end = 0, s = 0;
 
    for (int i=0; i<n; i++) {
        max_ending_here += temp[i];
 
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
        if (max_ending_here < 0) {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    
    return max_so_far;
}

ld fun(ld x) {
    vector<ld> temp(n);
    for(int i=0; i<n; i++) {
        temp[i] = vc[i] - x;
    } 
    
    ld poorness = 0;
    poorness = max(kadane(temp,n), poorness);
    
    for(int i=0; i<n; i++) {
        temp[i] *= -1.0;
    }
    
    poorness = max(kadane(temp,n), poorness);
    return poorness;
    
}

int main() {
    
    cin >> n;
    vc.resize(n);
    
    for(int i=0; i<n; i++) {
        cin >> vc[i];
    }
    
    
    ld l = -1*1e5;
    ld r = 1e5;
    
    ld epsilon = 1e-13;
    
    while(r - l > 1e-13) {
        ld m1 = l + (r-l)/3;
        ld m2 = r - (r-l)/3;
        
        ld f1 = fun(m1), f2 = fun(m2);
        if(f1 > f2) {
            l = m1;
        } else if(f1 < f2) {
            r = m2;
        } else {
            l = m1;
            r = m2;
        }
    }
    
    cout << fixed << setprecision(10) << fun(l);
    
    
    return 0;
}
