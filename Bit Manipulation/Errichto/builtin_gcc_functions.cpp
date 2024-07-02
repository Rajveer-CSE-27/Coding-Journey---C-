// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**

https://codeforces.com/blog/entry/73558

Builtin functions of GCC compiler.

**/

int count_set_bits(int x) {
    
    // time :: O(log2(x))
    return __builtin_popcount(x);
    
    // use __builtin_popcountll(x) for long long
}

bool parity(int x) {
    
    // returns true(1) if the number has odd parity (number of set bits are odd) else it returns false(0) for even parity (number of set bits are even). 
    // time :: O(log2(x))
    return __builtin_parity(x);
    
    // use __builtin_parityll(x) for long long
}

int cnt_leading_zeros(int x) {
    
    // It counts number of zeros before the first occurrence of one(set bit).
    // time :: O(log2(x))
    return __builtin_clz(x);
    
    // use __builtin_clzll(x) for long long 
}

int cnt_trailing_zeros(int x) {
    
    //Count no of zeros from last to first occurrence of one(set bit). 
    // time :: O(log2(x))
    
    return __builtin_ctz(x);
    // use __builtin_ctzll(x) for long long 
}


int main() {
    
    return 0;
    
}
