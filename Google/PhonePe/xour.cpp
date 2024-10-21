#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**

https://codeforces.com/contest/1971/problem/G
**/

void solve() {
  int n;
  cin >> n;
  
  vector<int> vc(n);
  
  
  map<string,priority_queue<int, vector<int>, greater<int>>> mp;
  
  
  for(int i=0; i<n; i++) {
    cin >> vc[i];
    bitset<32> b(vc[i]);
    string s = b.to_string();
    
    s = s.substr(0, 30);
    
    mp[s].push(vc[i]);
  }
  
  
  for(int i=0; i<n; i++) {
    bitset<32> b(vc[i]);
    string s = b.to_string();
    s = s.substr(0, 30);
    
    cout << mp[s].top() << " ";
    mp[s].pop();
  }
  
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
