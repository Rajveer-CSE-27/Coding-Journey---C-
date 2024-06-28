// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=d7kvyp6dfz8&list=PLb3g_Z8nEv1icFNrtZqByO1CrWVHLlO5g&index=5

Problem :: https://codeforces.com/contest/16/problem/E
**/

vector<vector<float>> matrix;
vector<float> dp;

float fun(int subset, int& n) {
    
    if(dp[subset] != -1.0) {
        return dp[subset];
    }
    
    int fishcnt = __builtin_popcount(subset);
    fishcnt++;
    int pairs = (fishcnt * (fishcnt - 1))/2;
    float p = 1.0/(float)pairs;
    
    float ans = 0.0;
    
    for(int bit_no = 0; bit_no < n; bit_no++) {
        
        if((subset & (1<<bit_no)) == 0) {//if fish not present in subset
            
            for(int j=0; j<n; j++) {
                if((subset & (1<<j))) {
                    ans += p * matrix[j+1][bit_no + 1] * fun((subset ^ (1<<bit_no)), n);
                }
            }
        }
    }
    return dp[subset] = ans;
}

int main() {
    
    int n;
    cin >> n;
    
    matrix.resize(n+1, vector<float>(n+1));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    int bitmask = (1<<n) - 1;
    dp.resize(bitmask+1, -1.0);
    
    dp[bitmask] = 1.0;
    
    for(int i=1; i<=n; i++) {
        float ans = fun(1<<i - 1,n);
        cout << fixed << setprecision(6) << ans << " ";
    }
    
    return 0;
}
