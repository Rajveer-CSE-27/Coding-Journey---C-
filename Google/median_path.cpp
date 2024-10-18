#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Tree with n nodes and n-1 edges.
Sum of median of all  odd length paths starting from root node.


Approach :: BFS
Each time 2 heap approach to find MEDIAN of running stream
**/

void solve() {
  
  int n;
  cin >> n;
  vector<int> node(n+1);
  for(int i=1; i<=n; i++) {
    cin >> node[i];
  }
  
  vector<vector<int>> tree(n+1);
  vector<bool> vis(n+1, false);
  
  for(int i=0; i<n-1; i++) {
    int n1,n2;
    cin >> n1 >> n2;
    tree[n1].push_back(n2);
    tree[n2].push_back(n1);
  }
  
  // everytime we need median. So it is like median of running stream
  
  
  queue<pair<int, pair<priority_queue<int, vector<int>, greater<int>>, priority_queue<int>>>> q;
  priority_queue<int, vector<int>, greater<int>> mn;
  
  priority_queue<int> mx;
  mx.push(node[1]);
  
  q.push({1, {mn,mx}});
  vis[1] = true;
  int iteration = 1;
  
  
  // {node, {min heap, max heap}}
  long long ans = 0;
  
  while(!q.empty()) {
    
    
    int sz = q.size();
    while(sz--) {
      
      pair<int, pair<priority_queue<int, vector<int>, greater<int>>, priority_queue<int>>> pr = q.front();
      
      q.pop();
      
      if(iteration&1) {
        ans += pr.second.second.top();
      }
      
      for(int adj:tree[pr.first]) {
        if(vis[adj] == false) {
          
          mn = pr.second.first;
          mx = pr.second.second;
          
          vis[adj] = true;
          int val = node[adj];
          
          if(iteration&1) {
            // need to make size of mn and mx heap equal. currently mx heap has 1 extra element
            
            if(val >= mx.top()) {
              mn.push(val);
            } else {
              
              mx.push(val);
              mn.push(mx.top());
              mx.pop();
              
            }
            
          } else {
            // need to make size of mx heap = 1 + size of mn heap
            if(val <= mx.top()) {
              mx.push(val);
            } else {
              mn.push(val);
              mx.push(mn.top());
              mn.pop();
            }
            
          }
          
          q.push({adj, {mn,mx}});
          
          
        }
      }
      
    }
    
    
    iteration++;
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
