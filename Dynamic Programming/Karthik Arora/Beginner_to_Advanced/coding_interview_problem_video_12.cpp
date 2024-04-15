#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Problem Statement :: 
    Coding interview problem
    
            Find the number of lists that exist and satisfy the following:
                            1. list contains exactly 'n' elements
                            2. all elements of the list are between 'low' and 'high'
                            3. sum of all elements is even
                Return answer modulo 10^9+7
                
    Constraints
    
            1 <= n <= 10^6
            1 <= low <= high <= 10^6
            
    Sample
            (n=3, low=1, high=2) - > 4
            (n=2, low=1, high=10) -> 50
**/

int main() {
    
    int mod = 1e9 + 7;
    int n, low, high;
    cin >> n >> low >> high;
    
    int cntOdd, cntEven;
    
    if(low%2 == 0 and high%2 == 0) {
        cntOdd = (high - low)/2;
        cntEven = cntOdd + 1;
    } else if(low%2 == 1 and high%2 == 1) {
        cntEven = (high - low)/2;
        cntOdd = cntEven + 1;
    } else {
        cntEven = (high - low)/2;
        cntEven++;
        cntOdd = cntEven;
    }
    
    // there is no need of vector as each time we are just considering prev values
    // vector<vector<ll>> dp(n+1, vector<ll>(2));
    
    // dp[1][0] = cntEven;
    // dp[1][1] = cntOdd;
    
    // for(int i=2; i<=n; i++) {
    //     // counting even at ith index.
    //     ll even = (((dp[i-1][0])%mod * (cntEven)%mod)%mod + ((dp[i-1][1])%mod * (cntOdd)%mod)%mod)%mod;
    //     dp[i][0] = even;
        
    //     // counting odd at ith index.
    //     ll odd = (((dp[i-1][0])%mod * (cntOdd)%mod)%mod + ((dp[i-1][1])%mod * (cntEven)%mod)%mod)%mod;
    //     dp[i][1] = odd;
    // } 
    // cout << dp[n][0];
    
    ll lastEvenCnt = cntEven;
    ll lastOddCnt = cntOdd;
    
    for(int i=2; i<=n; i++) {
        ll even = (((lastEvenCnt)%mod * (cntEven)%mod)%mod + ((lastOddCnt)%mod * (cntOdd)%mod)%mod)%mod;
        ll odd =  (((lastEvenCnt)%mod * (cntOdd)%mod)%mod + ((lastOddCnt)%mod * (cntEven)%mod)%mod)%mod;
        
        lastEvenCnt = even;
        lastOddCnt = odd;
    }
    
    cout << lastEvenCnt;
    
    return 0;
}
