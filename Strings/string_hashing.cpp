// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://cp-algorithms.com/string/string-hashing.html

String hashing ::
        Ek hash function ko use karke string ki hash value compute karenge.
        And hash values use karke kaafi kaam kar payenge like comparing strings, determining unique strings, etc.
        
        Brute force way to compare 2 strings is O(min(n,m)).
        With string hashing we will do it in -----------------> O(1).
    
    
Properties of our required hash function for string hashing :: 
        The goal of it is to convert a string into an integer, the so-called hash of the string.
        If two strings s and t are equal, then their hashes also have to be equal.
        If two hashes are equal then strings do not necessarily have to be equal.
        
        Using hashing will not be 100% deterministically correct,
        because two complete different strings might have the same hash (the hashes collide). 
        However, in a wide majority of tasks, this can be safely ignored as the probability of the hashes of two different strings colliding is still very small.

Polynomial rolling hash function :: 
        The good and widely used way to define the hash of a string s of length n is :
                
                hash(s) = (s[0] + s[1]*p + s[2]*(p^2) + s[3]*(p^3) + ... + s[n-1]*(p^(n-1))) modm
                where p and m are chosen positive numbers
        
        It is reasonable to make p a prime number roughly equal to the number of characters in the input alphabet.
        Eg. if lowercase English then p = 31
                // start with 'a' = 1, b = '2', c = '3', ....
            if both lowercase and uppercase then p = 53
        
        m should be a large number as it represents the set of all possible hash values.
        And P(2 random strings colliding) = 1/m
        Good choice is m = 1e9 + 9
        
See the compute_hash function in code.


Fast hash calculation of substrings of given string ::
        
        Problem :: Given a string s and 2 indices i,j
                   Compute hash value for substring s[i....j] efficiently.
            
        
        hash(s[i....j]) * (p^i) = (hash(s[0....j]) - hash(s[0...i-1])) modm

    See problem 2 in your strings Problem folder
    Hence we need to find the modular multiplicative inverse of  p^i and then perform multiplication in RHS to get answer.
    Read article for optimized way to avoid this multiplication.
    
    

Improve no-collision probability ::
    Ya to tum m ko increase karte raho.
    
    If our m ~ 1e9 and if we compare 1e6 different strings with each other then P(collision) ~ 1 which is bad.
    
    Trick :: 
        For each string compute 2 different hash values.
        Use two different p and you may/may not use different m's.
        
        Comparing 2 strings will be now comparing their pairs of hash values. If both equal then 2 strings are equal.
        And also this resuces P(collision) a lot lot lot.
**/


ll compute_hash(string& s) {
    // let s contains lowercase letters
    int p = 31;
    // if s contains both lowercase and uppercase then p = 53
    
    int m = 1e9 + 9;
    ll hash_val = 0;
    ll p_pow = 1;
    
    
    for(char c:s) {
        hash_val = (hash_val + (c - 'a' + 1)*p_pow) % m;
        p_pow = (p_pow * p)%m;
    }
    
    return hash_val;
}

int main() {
    
    // string s1 = "andjsdn";
    // string s2 = "asdfgh";
    // string s3 = "asdfgh";
    // cout << compute_hash(s1) << " " << compute_hash(s2) << " " << compute_hash(s3);
    
    return 0;
}
