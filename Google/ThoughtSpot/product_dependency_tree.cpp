#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;


ll ans;

int dfs(int node, int& n, vector<vector<int>>& tree, int parent) {
  
  
  vector<int> child;
  
  for(int adj:tree[node]) {
    if(adj != parent) {
      child.push_back(dfs(adj, n, tree, node));
    }
  }
  
  if(child.empty()) {
    return 1;
  }
  
  // 
  
  ll temp = 0;
  
  
  int cnt = 0;
  for(int x:child) {
    cnt += x;
  }
  
  for(int x:child) {
    ll temp2 = cnt - x;
    
    temp2 = (temp2%mod * x%mod)%mod;
    temp = (temp + temp2)%mod;
  }
  temp /= 2;
  
  cnt++; // for adding current node
  
  int remaining = n - cnt;
  temp = (temp%mod * remaining%mod)%mod;
  
  ans = (ans + temp)%mod;
  
  
  return cnt;
  
}

int main() {
    
  int n;
  cin >> n;
  
  vector<int> vc1(n-1), vc2(n-1);
  for(int i=0; i<n-1; i++) {
    cin >> vc1[i];
  }
  for(int i=0; i<n-1; i++) {
    cin >> vc2[i];
  }
  
  vector<vector<int>> tree(n);
  for(int i=0; i<n-1; i++) {
    tree[vc1[i]].push_back(vc2[i]);
    tree[vc2[i]].push_back(vc1[i]);
  }
  
  ans = 0;
  
  dfs(0, n, tree, -1);
  
  cout << ans;
  
  
  return 0;  
}
