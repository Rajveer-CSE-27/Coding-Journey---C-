// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int AND(int a, int b) {
    return a&b;
}
int OR(int a, int b) {
    return a|b;
}
int XOR(int a, int b) {
    return a^b;
}

int LEFTSHIFT(int a, int k) {
    // it will shift the bits of a by k units to left
    // this is equal to multiplying a * (2^k). because a bit originally at ith position will now be at i+k th position
    // hence answer 2^i --> 2^(i+k) for all i bits and overall answer will by multiplied by 2^k.
    
    int ans = a<<k;
    // jis direction me arrow hai uss direction me shift hoga. Here left
    // take care of integer overflow
    
    return ans;
    
}

int RIGHTSHIFT(int a, int k) {
    // it will shift the bits of a by k units to right
    //this is equal to dividing a /(2^k).
    
    int ans = a>>k;
    // here right
    
    return ans;
}

void print_all_bits(int x) {
    
    for(int bit_no = 0; bit_no < 32; bit_no++) {
        if(x & (1<<bit_no)) { // this line checks whether current bit is active or not
            cout << 1;
        } else {
            cout << 0;
        }
    }
    
    /**
    NOTE :: in above expression (1<<bit_no) could overflow also. Hence us 1LL instead of 1
    You can also use ((x>>bit_no) & 1) to check for the same. This will never overflow.
    **/
    
}

int main() {
    
    
    cout << AND(10,12) << '\n';
    cout << AND(5,5) << '\n';
    cout << OR(7,11) << '\n';
    cout << XOR(12, 16) << '\n';
    cout << XOR(15,15) << '\n';
    cout << LEFTSHIFT(2, 3) << '\n';
    cout << RIGHTSHIFT(101, 2) << '\n';
    
    print_all_bits(89);
    
    return 0;
    
}
