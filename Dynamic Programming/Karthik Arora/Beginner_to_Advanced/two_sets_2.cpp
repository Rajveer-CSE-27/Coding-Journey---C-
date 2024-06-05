// || जय जय जय बजरंग बली ||

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const ll modInverse2_with_1e9 = 500000004;
/**
Problem link :: https://www.cses.fi/problemset/task/1093

Approach :: 
    Consider it as finding the number of subsets from set {1,2,.....,n} such that the subset sum is :: (n*(n+1))/4.

    Edge case :: Note if (n*(n+1))/2 is odd then there exists no subset.
    Make a dp[sm+1][n+1] where sm = (n*(n+1))/4.
    
    dp[i][j] will tell number of subsets that we can build if the requied sum of subset is i and we are currently at value j.
    
    Note that dp[i][j] = dp[i-j][j+1] + dp[i][j+1]
    That is if we take value j in our sum then required sum will be i-j and we move to next index (j+1)
            if we do not take j in our sum the required sum will still be i and we move to next index (j+1).
        
    
    First handle all base cases.
    dp[i][i] = 1 for all i : [1 to n].
    dp[i][j] = 0 for all pairs i,j such that i < j. Becuase we cannot make sum = i with any valuues > i.
    
    if at any time :: i-j <= 0 then dp[i-j][j+1] = 0. Note i-j = 0 case already handled in base cases.
                      j > n then dp[i][j+1] = 0. Because we cannot take values > n.
    
    Hence go in diagonal fashion.
    

**/

int solve(int n) {
    int sm = (n*(n+1))/2;
    if(sm&1) {
        return 0;
    }
    
    sm /= 2;
    int dp[sm+1][n+1];
    
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            if(j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }
    
    for(int row=2; row<=sm; row++) {
        int i=row, j=1;
        
        // go in diagonal fashion
        while(i <= sm and j <= n) {
            
            // required sm = i, current index = j
            pair<int,int> pr1, pr2;
            pr1 = {i-j, j+1}; // take
            pr2 = {i, j+1}; // leave
            
            ll val1 = 0, val2 = 0;
            if(pr1.first >= 1 and pr1.second <= n) {
                val1 = dp[pr1.first][pr1.second];
            }
            if(pr2.first >= 1 and pr2.second <= n) {
                val2 = dp[pr2.first][pr2.second];
            }
            dp[i][j] = (val1 + val2)%mod;
            
            i++;
            j++;
        }
    }
    
    // return dp[sm][1]/2
    // for modulo arithmetic we cannot just divide by 2. We need to multiply by modinverse of 2
    return (dp[sm][1] * modInverse2_with_1e9)%mod;
    
}

int main() {
    
    int n;
    cin >> n;
    
    int ans = solve(n);
    cout << ans;
    
    
    return 0;    
}
