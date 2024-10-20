#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**
**/
void solve() {
  int n; 
  cin >> n;
  
  vector<int> vc(n);
  for(int i=0; i<n; i++) {
    cin >> vc[i];
  }
  
  // vc[i] <= i
  
  // only perfect square will have odd number of divisors.
  // find the count of subarrays having xor == perfect square.
  // subtract total subarrays - cnt
  
  // the max xor under this constraints = 2n
  // number of perfect squares = sqrt(2n)
  
  vector<int> m(2*n, 0);
  
  ll cnt = 0;
  int curr = 0;
  m[0]++;
  
  for(int i=0; i<n; i++) {
    
    curr ^= vc[i];
    
    for(int j=0; j*j < 2*n; j++) {
      
      if((curr ^ (j*j)) < 2*n) {
        cnt += m[(curr ^ (j*j))];
      }
      
    }
    
    m[curr]++;
    
  }
  
  
  ll ans = (((long long)n*((long long)n+1ll))/2ll);
  ans -= cnt;
  
  cout << ans;
  
}

  
int main() {
  
  int tc;
  cin >> tc;
  while(tc--) {
    solve();
    cout << '\n';
  }
  
  return 0;
  
  
}
