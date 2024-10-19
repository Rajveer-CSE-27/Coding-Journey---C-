#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;


/**
We have an array A of N elements. 
We will be asked Q queries. each query is in the form of a single integer, X, and we have to tell whether there exists an index i in the array such that the bitwise AND of A[i] and X equals 0. 
If such an index exists print YES, otherwise print NO.

Constraints : 1<=N<=1e5, 1<=Q<=1e5, 1<=A[i]<=1e5


Approach :: SOS DP

Basic logic : 
    Number to be found for x is subset of 1's complement of x
    dp[mask] = a[i] such that a[i] is subset of mask
**/

  
int main() {
  
  int n, q;
  cin >> n >> q;
  vector<int> vc(n);
  for(int i=0; i<n; i++) {
    cin >> vc[i];
  }
  
  int h = 0;
  int dp[4194306];
  memset(dp, 0, sizeof(dp));
  
  for(int i=0; i<n; i++) {
    dp[vc[i]] = vc[i];
    
    while((1<<h) <= vc[i]) {
      h++;
    }
  }
  
  for(int i=0; i<h; i++) {
    
    for(int mask = 0; mask < (1<<h); mask++) {
      if((mask & (1<<i))) {
        if(dp[mask] == 0) {
          
          dp[mask] = dp[mask^(1<<i)];
          
        }
        
      }
    }
    
  }
  
  
  for(int i=0; i<q; i++) {
    int x;
    cin >> x;
    
    int j = x^((1<<h) - 1);
    if(dp[j] == 0) {
      cout << -1 << " ";
    } else {
      cout << dp[j] << " ";
    }
    
  }
  
  
  return 0;
  
}
