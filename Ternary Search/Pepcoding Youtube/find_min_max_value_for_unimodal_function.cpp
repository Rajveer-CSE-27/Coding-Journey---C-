#include <bits/stdc++.h>
using namespace std;
#define double long double

/**
    -> Problem Statement :: Find the min/max value of a unimodal function.
    
    -> Let us try to find whether there will be a minima or maxima for a given function.
            -> If you are given a quadratic equation :: ax^2 + bx + c = 0
                            If a > 0 then downword parabola will be formed hence there will exist a minima.
                            If a < 0 the upward parabola will be formed hence there will exist a maxima.
            
            -> You can find minima / maxima by derivative. Then look at its neighbouring values to find whether it is minima or maxima.
            -> Note a unimodal function will have only 1 minima or 1 maxima.
                              

**/

double fun1(double x) {
    // f = 2x^2 - 12x + 7
    // not that this is a unimodal function which will give a minima. Hence apply ternary search to find minimum val.
    
    return 2 * x * x - 12* x + 7;
}

double fun2(double x) {
    // f = -2x^2 + 12x + 7
    // not that this is a unimodal function which will give a maxima. Hence apply ternary search to find maximum val.
    
    
    return -2 * x * x + 12*x + 7;
}


double ternary_Search_Min(double l, double r) {
    double epsilon = 1e-9;
    
    while(r - l > epsilon) {
        double m1 = l + (r - l)/3;
        double m2 = r - (r - l)/3;
        
        double f1 = fun1(m1), f2 = fun1(m2);
        
        if(f1 < f2) {
            // hence min value l,f2 ke beech hi hogi
            r = m2;
        } else if(f1 > f2) {
            // hence min value f1,r ke beech hi hogi
            l = m1;
        } else {
            l = m1;
            r = m2;
        }
    }
    return fun1(l); // this or fun1(r) both will have min values
}

double ternary_Search_Max(double l, double r) {
    double epsilon = 1e-9;
    
    while(r - l > epsilon) {
        double m1 = l + (r - l)/3;
        double m2 = r - (r - l)/3;
        
        double f1 = fun2(m1), f2 = fun2(m2);
        
        if(f1 < f2) {
            // hence max value f1,r ke beech hi hogi
            l = m1;
        } else if(f1 > f2) {
            // hence max value l,f2 ke beech hi hogi
            r = m2;
        } else {
            l = m1;
            r = m2;
        }
    }
    return fun2(l);
}

int main() {
    
    // for function 1
    double l = INT_MIN, r = INT_MAX;
    double mnValue = ternary_Search_Min(l,r);
    
    // for function 2
    l = INT_MIN, r = INT_MAX;
    double mxValue = ternary_Search_Max(l,r);
    
    cout << mnValue << '\n' << mxValue;
    
    
    return 0;
}
