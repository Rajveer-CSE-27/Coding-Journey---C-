#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;


// recursion


void fun(int sm1, int sm2, vector<int>& vc, vector<bool>& vis, int& ans, int& n) {
  
  if(sm1 == sm2) {
    if(sm1 > ans) {
      ans = sm1;
    }
  }
  
  
  
  for(int j=0; j<n; j++) {
    if(vis[j] == false) {
      
      vis[j] = true;
      fun(sm1 + vc[j], sm2, vc, vis, ans, n);
      fun(sm1, sm2 + vc[j], vc, vis, ans, n);
      vis[j] = false;     
    }
  }
  
}

int main() {
  
  int n;
  cin >> n;
  vector<int> vc(n);
  for(int i=0; i<n; i++) {
    cin >> vc[i];
  }
  
  vector<bool> vis(n, false);
  int ans = -1;
  fun(0,0,vc,vis, ans,n);
  
  
  cout << ans;
  
  return 0;
}
