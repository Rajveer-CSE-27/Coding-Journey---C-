// || जय जय जय बजरंग बली ||

//https://www.youtube.com/watch?v=7FmL-WpTTJ4&list=PLb3g_Z8nEv1icFNrtZqByO1CrWVHLlO5g&index=2
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void add(int& bitMask, int x) {
    // need to add number x to the set that is represented by bitmask
    // xor the xth bit with 1
    
    bitMask = (bitMask ^ (1 << (x-1)));
}

void remove(int& bitMask, int x) {
    // need to remove number x from the set that is represented by bitmask
    // xor the xth bit with 1
    
    bitMask = (bitMask ^ (1 << (x-1)));
}

void display(int bitMask) {
    
    // let the range of the set be from 1 to 10
    for(int bit_no = 0; bit_no < 10; bit_no++) {
        
        // checking whether bit_no-th bit is set in bitmask. If yes then bit_no is a part of the set that is represented by bitmask
        if(bitMask & (1 << bit_no)) {
            cout << bit_no + 1 << " ";
        }
    }
    cout << '\n';
}

int main() {
    
    int bitMask = 15;
    display(bitMask);
    remove(bitMask, 2);
    display(bitMask);
    add(bitMask, 7);
    display(bitMask);
    
    return 0;
}

