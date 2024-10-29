#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;


// we need to move a horse
// and reach destination in minimum moves

// bfs


int dx[8] = {2,2,-2,-2,1,-1,1,-1};
int dy[8] = {1,-1,1,-1,2,2,-2,-2};

void solve() {
  
  int n,m;
  cin >> n >> m;
  int r1,c1,r2,c2;
  cin >> r1 >> c1 >> r2 >> c2;
  
  vector<vector<bool>> vis(n+1,vector<bool>(m+1, false));
  vis[r1][c1] = true;
  
  
  queue<pair<int,int>> q;
  q.push({r1,c1});
  
  
  int moves = 0;
  
  while(!q.empty()) {
    
    int sz = q.size();
    
    while(sz--) {
      pair<int,int> pr = q.front();
      q.pop();
      
      if(pr.first == r2 and pr.second == c2) {
        cout << moves;
        return;
      }
      
      for(int k=0; k<8; k++) {
        int x = pr.first + dx[k];
        int y = pr.second + dy[k];
        
        if(x >= 1 and y >= 1 and x <= n and y <= m and vis[x][y] == false) {
          vis[x][y] = true;
          q.push({x,y});
        }
      }
      
    }
    
    moves++;
  }
  
  
  cout << -1; // not possible to reach r2,c2 anyhow
  
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
