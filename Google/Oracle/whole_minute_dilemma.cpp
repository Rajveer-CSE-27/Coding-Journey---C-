#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;


/**
https://favtutor.com/articles/whole-minute-dilemma/

mod60 karke map bana lo
**/

int main() {
  
  int n;
  cin >> n;
  vector<int> vc(n);
  for(int i=0; i<n; i++) {
    cin >> vc[i];
  }
  
  map<int,int> mp;
  for(int i=0; i<n; i++) {
    mp[vc[i]%60]++;
  }
  
  long long ans = 0;
  
  for(auto it:mp) {
    int key = it.first;
    int val = it.second;
    
    if(key == 0 or key == 30) {
      ans += (val*(val - 1));
    } else {
      
      ans += val * mp[60 - key];
      
      
    }
    
  }
  
  cout << ans/2;
  
  return 0;  
}
