#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

// mat[i][j] = 1 represents that we can open our research centre at i,j
// also during bfs we can only travel to cells having mat[i][j] == 1


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

vector<vector<int>> bfs(int i, int j, vector<vector<int>>& mat, int& n) {
  
  vector<vector<bool>> vis(n, vector<bool>(n, false));
  vis[i][j] = true;
  vector<vector<int>> dist(n, vector<int>(n));
  dist[i][j] = 0;
  
  
  queue<pair<int,int>> q;
  q.push({i,j});
  
  while(!q.empty()) {
    
    pair<int,int> pr = q.front();
    q.pop();
    
    for(int k=0; k<4; k++) {
      int x = pr.first + dx[k];
      int y = pr.second + dy[k];
      
      if(x >= 0 and y >= 0 and x < n and y < n and vis[x][y] == false and mat[x][y] == 1) {
        vis[x][y] = true;
        dist[x][y] = dist[pr.first][pr.second] + 1;
        q.push({x,y});
      }
    }
    
  }
  
  return dist;
  
}

void solve() {
  int n,m;
  cin >> n >> m;
  
  vector<vector<int>> mat(n, vector<int>(n));
  vector<vector<int>> element(m, vector<int>(2));
  
  for(int i=0; i<m; i++) {
    cin >> element[i][0] >> element[i][1];
    
    element[i][0]--;
    element[i][1]--; 
    // because we need 0 based indexing
    
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> mat[i][j];
    }
  }
  
  int ans = INT_MAX;
  
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      
      if(mat[i][j] == 1) {
        // we can form research centre here
        
        vector<vector<int>> dist = bfs(i,j,mat,n);
        
        int mxDist = 0;
        for(int k=0; k<m; k++) {
          mxDist = max(mxDist, dist[element[k][0]][element[k][1]]);
        }
        
        ans = min(ans, mxDist);
        
      }
      
      
    }
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
