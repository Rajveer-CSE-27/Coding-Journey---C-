#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**
**/

  
int main() {
  
  int n;
  cin >> n;
  vector<int> vc(n);
  for(int i=0; i<n; i++) {
    cin >> vc[i];
  }
  
  // constraint :: vc[i] <= n
  
  // first using sieve to calculate number of divisors of each number from 1 to pow(2, floor(log2(n)) + 1) - 1 
  
  int m = pow(2, floor(log2((double)n)) + 1) - 1;
  
  // sieve
  vector<int> sieve(m+1, 2); // every number has 1 and divisor itself
  
  sieve[0] = 0;
  sieve[1] = 1;
  
  for(int i=2; i*i<=m; i++) {
    for(int j=i*i; j<=m; j+=i) {
      
      if(j == i*i) {
        sieve[j]++;
      } else {
        sieve[j] += 2; // i,e both i and j/i will be valid divisors
      }
    }
  }
  
  int ans = 0;
  
  for(int i=0; i<n; i++) {
    
    int xr = 0;
    for(int j=i; j<n; j++) {
      xr ^= vc[j];
      
      if(xr != 0 and sieve[xr]%2 == 0) {
        ans++;
      }
    }
  }
  
  
  cout << ans; 
  
  return 0;
  
  
  
  
}
