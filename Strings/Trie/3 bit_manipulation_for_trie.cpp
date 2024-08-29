// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
**/

int main() {
    
    // i starts from 0
    
    // if you want to check whether ith bit in a number x is set(1)
    int x = 9;
    int i = 3;
    
    if((x>>i)&1 == 1) {
        cout << "YES\n";
    }
    
    // if you want to set ith bit in a number x
    
    x = 15;
    i = 4;
    
    int ans = ((1<<i)|x);
    cout << ans;
    
    return 0;
}
