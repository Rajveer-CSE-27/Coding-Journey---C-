// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**
https://www.youtube.com/watch?v=xXKL9YBWgCY&list=PLl0KD3g-oDOHpWRyyGBUJ9jmul0lUOD80&index=1

You are given N numbers. 
Check if there is a subset of them, with the sum equal to target value S.
N <= 20

Subset sum. 
If n is small then you can create a mask which will represent any subset of a given set. Then you can iterate through all possible numbers
between 0 to mask and check all the subsets.

**/

bool check(int n, vector<int>& vc, int x) {
    
    for(int mask=0; mask <= ((1<<n) - 1); mask++) {
        ll subset_sm = 0;
        
        for(int bit_no = 0; bit_no < n; bit_no++) {
            if(mask & (1<<bit_no)) {
                subset_sm += vc[bit_no];
            }
        }
        
        if(subset_sm == x) {
            return true;
        }
    }
    return false;
}

int main() {
    
    
    int n;
    cin >> n;
    vector<int> vc(n);
    for(int i=0; i<n; i++) {
        cin >> vc[i];
    }
    int x;
    cin >> x;
    
    if(check(n, vc, x) == true) {
        cout << "YES"; 
    } else {
        cout << "NO";
    }
    
    return 0;
    
}
