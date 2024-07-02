// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**
Problem :: You are given a sequence of N ≤ 1e7 numbers, each from interval [0,1e9].
           How many different values appear in the sequence?
        Don't use set or unordered_set because they quite slow.
        
Approach :: use bitset of size 1e9. And for each n mark it set in the bitset. At last count all set bits.

Time Complexity :: Why this works ?
                The time complexity is 𝑂(𝑁 + MAX_X/32), 
                space is 𝑂(MAX_X/32). 
                This will use 128 MB memory (one billion bits).
                
                Creating a boolean array instead would take 1GB because one element of this array takes the whole byte.
                Remember that bitset is more memory-optimized than a boolean array!

**/


int main() {
    
    int n;
    cin >> n;
    
    bitset<1000000001> visited;
    
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        visited[x] = 1;
    }
    
    int ans = visited.count();
    cout << ans;
    
    return 0;
    
}
