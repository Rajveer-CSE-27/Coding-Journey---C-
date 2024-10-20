#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**
Observation based.
Recursion tree banake dekho you will get it
**/

  
int main() {
  
  int n;
  cin >> n;
  vector<int> vc(n);
  
  long long sm = 0;
  for(int i=0; i<n; i++) {
    cin >> vc[i];
    sm += vc[i];
  }
  
  sort(vc.rbegin(), vc.rend());
  
  // all elements of vc[i] will be added till 2nd last level of our recursion tree
  // 2nd last level = floor(log2(n)) + 1
  
  long long ans = (floor((double)log2((double)n)) + 1ll) * (sm);
  
  // at last level there will be (n - pow(2, floor(log2(n))))  * 2 elements
  // hence add greatest elements till this count
  
  
  int cnt = n - pow(2, floor((double)log2((double)n)));
  cnt *= 2;
  
  for(int i=0; i<cnt; i++) {
    ans += vc[i];
  }
  
  cout << ans;
   
  
  return 0;
  
  
}
