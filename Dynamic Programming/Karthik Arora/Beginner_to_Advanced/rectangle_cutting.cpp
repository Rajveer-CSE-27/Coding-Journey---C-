#include <bits/stdc++.h>
using namespace std;
#define ll long long


/**
Problem link :: https://cses.fi/problemset/result/9017333/

Appraoch :: 
        Let us form a dp matrix of maxSize of constraints.
        dp[i][j] = minimum nnumber of operations required to convert rectangle with dimensions :: i*j to squares.
        
        Base cases :: for all i==j : dp[i][j] = 0.
        For all i :: dp[i][1] = i-1
        For all j :: dp[1][j] = j-1;
        
        Now for calculating dp[i][j] :
            -> If we decide to cut on 1st dimension then there are multiple cuts possible ::
                        (i,j) -> (1,j) + (i-1, j) + 1 // we add 1 becuase that is the cost of cutting
                        (i,j) -> (2, j) + (i-2, j) + 1
                        .
                        .
                        .
                        (i,j) -> (i/2, j) + (i/2, j) + 1
                        
            -> If we decide to cut on the 2nd dimension then ::
                        (i,j) -> (i,1) + (i,j-1) + 1
                        (i,j) -> (i,2) + (i, j-2) + 1
                        .
                        .
                        .
                        (i,j) -> (i,j/2) + (i,j/2) + 1
                        
            dp[i][j] = minimum of all of these possible cuts. Hence minimum of all these values.
            
**/

int dp[501][501];

int main() {
    
    memset(dp, -1, sizeof dp);
    
    // handling base cases
    for(int i=1; i<=500; i++) {
        dp[i][i] = 0;
    }
    
    for(int i=1; i<=500; i++) {
        dp[i][1] = i-1;
        dp[1][i] = i-1;
    }
    
    for(int i=2; i<=500; i++) {
        for(int j=2; j<=500; j++) {
            if(dp[i][j] == -1) {
                int halfRow = i/2;
                int ans = INT_MAX;
                for(int k=1; k<=halfRow; k++) {
                    int val = 1 + dp[k][j] + dp[i - k][j];
                    ans = min(ans, val);
                }
                
                int halfCol = j/2;
                for(int k=1; k<=halfCol; k++) {
                    int val = 1 + dp[i][k] + dp[i][j - k];
                    ans = min(ans, val);
                }
                
                dp[i][j] = ans;
            }
        }
    }
    
    int a,b;
    cin >> a >> b;
    
    cout << dp[a][b];
    return 0;
}
