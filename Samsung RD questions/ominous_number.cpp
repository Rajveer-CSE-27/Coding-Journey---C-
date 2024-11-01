#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;


// simple solution

int main() {
  
  int l,r,k;
  cin >> l >> r >> k;
  
  int n;
  cin >> n;
  vector<int> vc(n);
  for(int i=0; i<n; i++) {
    cin >> vc[i];
  }
  
  
  int ans = 0;
  
  for(int i=l; i<=r; i++) {
    
    int temp = i;
    int freq[10] = {0};
    
    while(temp > 0) {
      freq[temp%10]++;
      temp /= 10;
    }
    
    int cnt = 0;
    for(int j=0; j<n; j++) {
      cnt += freq[vc[j]];
    }
    
    if(cnt < k) {
      ans++;
    }
  }
  
  cout << ans;
  return 0;
}
