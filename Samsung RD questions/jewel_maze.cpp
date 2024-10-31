#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

// recursion use karo

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void fun(int i, int j, int coins, vector<vector<int>>& maze, vector<vector<bool>>& vis, vector<vector<int>>& finalPath, int& mxCoins, int& n) {
  
  if(i == n-1 and j == n-1) {
    if(coins > mxCoins) {
      mxCoins = coins;
      
      for(int r=0; r<n; r++) {
        for(int c=0; c<n; c++) {
          if(vis[r][c] == true) {
            finalPath[r][c] = 3;
          } else {
            finalPath[r][c] = maze[r][c];
          }
        }
      }
    }
    
    return;
  }
  
  
  for(int k=0; k<4; k++) {
    int x = i + dx[k];
    int y = j + dy[k];
    
    if(x >= 0 and y >= 0 and x < n and y < n and vis[x][y] == false) {
      
      vis[x][y] = true;
      if(maze[x][y] == 2) {
        fun(x,y,coins + 1, maze, vis, finalPath, mxCoins, n);
      } else if(maze[x][y] == 0) {
        fun(x,y,coins, maze, vis, finalPath, mxCoins, n);
      }
      
      vis[x][y] = false;
      // backtrack
      
    }
  }
  
}


void solve() {
  
  int n;
  cin >> n;
  
  vector<vector<int>> maze(n, vector<int>(n));
  vector<vector<bool>> vis(n, vector<bool>(n, false));
  vector<vector<int>> finalPath(n, vector<int>(n));
  
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> maze[i][j];
    }
  }
  
  // maze[i][j] = 0 means only path, maze[i][j] = 1 means wall, maze[i][j] = 2 means coin
  
  int mxCoins = -1;
  
  vis[0][0] = true;
  
  if(maze[0][0] == 0) {
    fun(0,0,0,maze,vis,finalPath, mxCoins, n);
  } else {
    fun(0,0,1,maze,vis,finalPath, mxCoins, n);
  }
  
  
  cout << mxCoins << '\n';
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cout << finalPath[i][j] << " ";
    }
    cout << '\n';
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
