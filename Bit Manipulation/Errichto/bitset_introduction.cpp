// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**

https://codeforces.com/blog/entry/73558
https://www.geeksforgeeks.org/cpp-bitset-and-its-application/

Bitsets : 
        Definition :: A bitset is an array of bools but each boolean value is not stored in a separate byte instead,
                      bitset optimizes the space such that each boolean value takes 1-bit space only,
                      so space taken by bitset is less than that of an array of bool or vector of bool. 
                     
        Note ::       Size must be specified prior like array.
                      2 bitsets pe operation karne ke liye size same honi chahiye.

        Initialization :: 
                3 methods :: 
                    -> bitset<size> name :: All the bits will be set to zero.
                    -> bitset<size> name(DECIMAL_NUMBER) :: Bitset will represent the given decimal number in binary form.
                    -> bitset<size> name("Binary_String") :: Bitset will represent the given binary string.
                    
        
        Functions :: 
                let there be a bitset<10> b;
                
                -> b.any() will return true if  any bit is set in b.
                -> b.all() will return true if  all bits are set in b.
                -> b.none() will return true if  none bits are set in b.
                
                -> b.test(i) : Returns the boolean value at the given index.
                -> b.set(i) : Set the bit value at the given index to 1.
                -> b.reset(i) : Set the bit value at a given index to 0.
                -> b.flip(i) : Flip the bit value at the given index.
                
                -> b.count() : Count the number of set bits.
                -> b.size() : Returns size of the bitset.
                
                -> string s = b.to_string() : Converts bitset to string
                -> b.to_ulong() : Converts bitset to unsigned long.
                -> b.to_ullong() : Converts bitset to unsigned long long.
                
        Operators :: 
            Supports all bitwise operations ::
            &, |, ^, >>=, <<=, &=, ~, etc.
            
        Time Complexity :: The complexity of bitwise operations is 𝑂(𝑠𝑖𝑧𝑒/32) or 𝑂(𝑠𝑖𝑧𝑒/64), 
                           it depends on the architecture of your computer. Actually it is O(size/word)
        
        
**/


int main() {
    
    bitset<4> b1(7); // it will add zero if bitset not filled
    bitset<4> b2("1101"); 
    bitset<6> b3;
    
    cout << b1 << '\n' << b2 << '\n' << b3 << '\n';
    
    bitset<4> res = b1&b2; // note 2 bitsets pe operation karne ke liye size same honi chahiye.
    cout << res << '\n';
    
    cout << (b1 &= b2) << '\n';
    
    b1 = 9; // 9 = 1001
    
    res = ~b1;
    cout << res << '\n';
    
    cout << res.any() << '\n';
    cout << b3.size() << '\n';
    
    string s = res.to_string();
    cout << s << '\n';
    
    return 0;
    
}
