#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.geeksforgeeks.org/minimum-iterations-pass-information-nodes-tree/
**/

bool comp(pair<int,int> p1, pair<int,int> p2) {
  
  // child having highest size will be given priority
  return (p1.first >= p2.first);
}

int dfs(int node, vector<vector<int>>& tree, vector<vector<pair<int,int>>>& child) {
  
  int totalSize = 1;
  
  for(int adj:tree[node]) {
    int sz = dfs(adj, tree, child);
    totalSize += sz;
    
    child[node].push_back({sz,adj});
  }
  
  return totalSize;
  
}

void dfs2(int node, int currTime, vector<vector<pair<int,int>>>& child, vector<int>& mxTime) {
  
  
  mxTime[node] = currTime;
  
  if(child[node].empty()) {
    return;
  }
  
  int m = child[node].size();
  
  for(int i=0; i<m; i++) {
    dfs2(child[node][i].second, currTime + i + 1, child, mxTime);
  }
  
}

 
int main() {
  
  int n, constX;
  cin >> n >> constX;
  
  vector<vector<int>> tree(n);
  
  for(int i=0; i<n-1; i++) {
    int n1,n2;
    cin >> n1 >> n2;
    
    tree[n1].push_back(n2);
  }
  
  vector<vector<pair<int,int>>> child(n);
  
  dfs(0, tree, child);
  
  for(int i=0; i<n; i++) {
    sort(child[i].begin(), child[i].end(), comp);
  }
  
  vector<int> mxTime(n,0);
  
  dfs2(0, 0, child, mxTime);
  
  
  int ans = *max_element(mxTime.begin(), mxTime.end());
  cout << ans;
  
  return 0;
}
