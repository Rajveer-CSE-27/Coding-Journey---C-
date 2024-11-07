#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;


void solve() {
  
  int n,k;
  vector<int> pots(n+1, 0);
  
  cin >> n >> k;
  for(int i=1; i<=n; i++) {
    cin >> pots[i];
  }
  
  vector<vector<int>> dp(n+1, vector<int>(k+1, 1e8));
  // dp[i][j] = minimum coins to fill the ith pot if (j-1) pots have already been filled
  
  sort(pots.begin(), pots.end());
  
  int ans = 1e8;
  
  
  // base case
  for(int i=1; i<=n; i++) {
    dp[i][1] = pots[i]*(n - i + 1);
  }
  
  // dp[i][1] = minimum stones required to fill the ith pot with k = 1
  
  for(int i=1; i<=n; i++) {
    for(int j=2; j<=k; j++) {
      
      //ith pot needs to be filled when j-1 pots have already been filled
      for(int l=i+1; l<=n; l++) {
        // let lth pot had been filled on j-1 th step
        
        dp[i][j] = min(dp[i][j], dp[l][j-1] + pots[i]*(l-i));
        
      }
    }
  }
  
  for(int i=1; i<=n; i++) {
    ans = min(ans, dp[i][k]);
  }
  
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
