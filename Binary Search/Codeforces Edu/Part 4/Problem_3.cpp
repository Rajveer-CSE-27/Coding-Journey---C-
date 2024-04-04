#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Problem link :: https://codeforces.com/edu/course/2/lesson/6/4/practice/contest/285069/problem/C

Approach :: Maximum Average using binary search

    -> Let x be the ratio that is specified in the problem.
    -> The variable x has a bad-good sequence :: 11111111110000000000.....
    -> We need to find maximum good x. So we will do binary search.
    
    -> To check whether a particular x is good :: 
        If we are able to select exactly k items such that ratio is >= x then x is good.
        
        Now :: (a1 + a2 + a3 + .... + ak)/(b1 + b2 + b3 + ..... + bk) >= x
               (a1 + a2 + a3 + .... + ak) >= x * (b1 + b2 + b3 + ..... + bk)
               (a1 + a2 + a3 + .... + ak) - x*(b1 + b2 + b3 + ..... + bk) >= 0
               
               So we just need to find k pairs such that this inequality is satisfied.
        
        We will sort in decreasing order wrt (ai - bi) value.
        So greatest of these values will tend to generate better results on LHS of the inequality. because both bi and ai > 0.
        

**/

int n,k;
vector<pair<double,double>> vc;

bool is_good(double x) {
    
    priority_queue<double> pq;
    for(int i=0; i<n; i++) {
        double temp = vc[i].first - x*(vc[i].second);
        pq.push(temp);
    }
    
    double sm = 0;
    for(int i=0; i<k; i++) {
        sm += pq.top();
        pq.pop();
    }
    
    return (sm >= 0);
}


int main() {
    
    cin >> n >> k;
    vc.resize(n);
    for(int i=0; i<n; i++) {
        cin >> vc[i].first >> vc[i].second;
    }
        
    double low = 0; // definitely good value as ratio >= 0
    double high = 1e6; // by constraints the greatest ration possible is 1e5. Lets take 1e6 for safety and this is definitely bad as no ratio >= 1e6 exist
    
    // binary search on real number
    for(int i=0; i<60; i++) {
        double mid = (low + high)/2;
        
        if(is_good(mid) == true) {
            low = mid;
        } else {
            high = mid;
        }
    }
    
    cout << setprecision(12) << high;
    
    return 0;    
    
}
