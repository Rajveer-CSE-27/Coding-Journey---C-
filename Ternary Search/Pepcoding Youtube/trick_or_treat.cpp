#include <bits/stdc++.h>
using namespace std;

/**
    Problem Link :: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3349
    
    Approach :: 
        If we start from least value of x-coordinate possible to highest value then first our time would decrease then increase staedily.
        Hence this is a unimodal function. Therefore apply ternanry search.
        
        By time we refer to total time taken by all people to gather at (x,0).

**/

int n;
vector<pair<double,double>> vc;

double fun(double x) {
    
    // in question it is hinted to use euclidean distance.
    double mxTime = 0;
    for(int i=0; i<n; i++) {
        double time = sqrt((vc[i].first - x)*(vc[i].first - x) + (vc[i].second * vc[i].second));
        //because speed is 1m/s
        if(mxTime < time) {
            mxTime = time;
        }
    }
    return mxTime;
}

int main() {
    
    cin >> n;
    vc.resize(n);
    for(int i=0; i<n; i++) {
        cin >> vc[i].first >> vc[i].second;
    }
    
    double l = -200000;
    double r = 200000;
    
    double epsilon = 1e-8;
    
    while(r - l > epsilon) {
        double m1 = l + (r-l)/3;
        double m2 = r - (r-l)/3;
        
        double f1 = fun(m1), f2 = fun(m2);
        
        if(f1 > f2) { // because we are dealing with continous values hence no m1-1 or m2+1
            l = m1;
        } else if(f1 < f2) {
            r = m2;
        } else {
            l = m1;
            r = m2;
        }
    }
    
    cout << fixed << setprecision(11) << r << " " << fun(r);
    return 0;
}
