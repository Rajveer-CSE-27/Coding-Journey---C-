#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

// answer is number of unique slopes from tim's house

int main() {
  
  int n,m;
  cin >> n >> m;
  
  // m always = 2
  
  vector<pair<int,int>> vc(n);
  for(int i=0; i<n; i++) {
    cin >> vc[i].first >> vc[i].second;
  }
  int timX, timY;
  cin >> timX >> timY;
  
  
  set<double> st;
  
  bool inf = false;
  
  for(int i=0; i<n; i++) {
    if(vc[i].first == timX) {
      // slope is infinity
      inf = true;
    } else {
      double d = (double)((double)vc[i].second - (double)timY)/(double)((double)vc[i].first - (double)timX);
      st.insert(d);
    }
  }
  
  int ans = 0;
  if(inf == true) {
    ans++;
  }
  
  if(!st.empty()) {
    ans += st.size();
  }
  
  cout << ans;
  
  return 0;
}
