#include <bits/stdc++.h>
using namespace std;

/**
Problem Link :: https://www.codechef.com/problems/ICM2003?tab=statement

    -> Approach ::
        Given the function :: (x^2 + bx + c)/sin(x)
        For the interval [0,pi/2] this is a unimodal function with 1 minima and we need to find that minima.
        
        Check at :: desmos graph website.
        
        ************ For using ternary search it is very important to prove that for a given interval tho function is unimodal*******************
        
    -> Hence use ternary search with epsilon :: 1e-6 as given in the question.
**/

const double pie = 3.14159265358979323846;
int b,c;

double fun(double x) {
    double v1 = x*x + b*x + c;
    v1 /= sin(x);
    
    return v1;
}

double ternary_search_min() {
    double l = 0;
    double r = pie/2;
    
    double epsilon = 1e-6;
    while(r - l > epsilon) {
        double m1 = l + (r - l)/3;
        double m2 = r - (r - l)/3;
        
        double f1 = fun(m1), f2 = fun(m2);
        
        if(f1 > f2) {
            l = m1;
        } else if(f2 > f1) {
            r = m2;
        } else {
            l = m1;
            r = m2;
        }
    }
    return fun(l);
}

void solve() {
    
    cin >> b >> c;
    
    double mn = ternary_search_min();
    cout << setprecision(12) << mn;
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
