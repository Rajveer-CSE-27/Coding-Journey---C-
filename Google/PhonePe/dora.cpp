#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;


void dijkstra(int& n, vector<vector<int>>& v1, vector<vector<int>>& v2, int& s, int& d, int& ans) {
  
  vector<vector<int>> dp(n, vector<int>(2, INT_MAX));
  dp[s][0] = 0;
  dp[s][1] = 0;
  
  priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
  
  pq.push({0, {s, 0}});
  //pq.push({0, {s, 1}}); she cannot switch at start iself
  
  while(!pq.empty()) {
    
    pair<int, pair<int,int>> pr = pq.top();
    pq.pop();
    
    int dis = pr.first;
    int node = pr.second.first;
    int switched = pr.second.second;
    
    if(dp[node][switched] < dis) {
      continue;
    }
    
    
    for(int i=0; i<n; i++) {
      
      int next = i;
      
      if(switched == 1) {
        
        
        if(node != s and v2[node][next] != -1) { // we can go from node to next
          int temp = v2[node][next] + dis;
          
          if(dp[next][switched] > temp) {
            dp[next][switched] = temp;
            pq.push({temp, {next, switched}});
          }
        }
        
      } else {
        
        // not make a switch
        if(v1[node][next] != -1) {
          
          int temp = v1[node][next] + dis;
          
          if(dp[next][switched] > temp) {
            dp[next][switched] = temp;
            pq.push({temp, {next, switched}});
          }
        }
        
        // make a switch now
        if(node != s and v2[node][next] != -1) { 
          int temp = v2[node][next] + dis;
          
          if(dp[next][1] > temp) {
            dp[next][1] = temp;
            pq.push({temp, {next, 1}});
          }
        }
        
      }
      
    }
    
  }
  
  
  int res = dp[d][1]; // because switch must occur once
  
  if(res != INT_MAX) {
    
    if(ans == -1) {
      ans = res;
    } else {
      ans = min(ans, res);
    }
    
  }
  
  
  
}
  
int main() {
  
  int n;
  cin >> n;
  
  vector<vector<int>> boat(n, vector<int>(n));
  vector<vector<int>> plane(n, vector<int>(n));
  
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> boat[i][j];
    }
  }
  
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> plane[i][j];
    }
  }
 
  int source, destination;
  cin >> source >> destination;
  
  // 1 based to 0 based indexing
  source--;
  destination--;
  
  int ans = -1;
  
  dijkstra(n, boat, plane, source, destination, ans);
  dijkstra(n, plane, boat, source, destination, ans);
  
  cout << ans;
  
  
  return 0;
  
}
