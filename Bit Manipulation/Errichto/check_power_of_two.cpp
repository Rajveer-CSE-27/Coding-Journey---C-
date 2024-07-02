// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

bool approach1(int x) {
    // log2 approach
    // time : O(1), space : O(1);
    
    return ceil(log2(x)) == floor(log2(x));
    
}

bool approach2(int x) {
    
    // cntSetBits approach
    // time : O(logx), space : O(1)
    
    
    int cnt = 0;
    while(x > 0) {
        if(x&1) {
            cnt++;
        }
        x >>= 1; // right shift i.e divide by 2
    }
    
    return (cnt==1);
    
}

bool approach3(int x) {
    
    // check if only rightmost bit is set.
    // if number is power of 2 then x-1 number will have all set bits from left to rightmost - 1.
    
    // hence x & (not(x-1)) == x
    // time : O(1), space : O(1)
    
    
    if(x <= 0) {
        return false;
    }
    
    if((x & (~(x-1))) == x) {
        return true;
    }
    return false;
}

int main() {
    
    
    cout << approach3(16);
    return 0;
    
}
