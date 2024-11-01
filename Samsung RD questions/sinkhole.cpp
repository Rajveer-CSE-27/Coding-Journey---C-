#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;


// binary search on answer

int check(int x, int& n, int& m, vector<vector<int>>& grid, int& xb, int& yb, int& xt, int& yt) {
  
  // we need to check minimum number of ones that exist among all squares of size x*x
  int mn = INT_MAX;
  
  for(int i=x-1; i<n; i++) {
    for(int j=x-1; j<m; j++) {
      
      // let square ends at i,j
      int ones = grid[i][j];
      if(i-x >= 0) {
        ones -= grid[i-x][j];
      }
      if(j-x >= 0) {
        ones -= grid[i][j-x];
      }
      if(i-x >= 0 and j - x >= 0) {
        ones += grid[i-x][j-x];
      }
      
      if(mn > ones) {
        mn = ones;
        
        if(mn <= 1) {
          xb = i;
          yb = j - x + 1;
          xt = i - x + 1;
          yt = j;
        }
      }
      
    }
  }
  
  
  return mn;
}

void solve() {
  
  int n,m;
  cin >> n >> m;
  
  vector<vector<int>> grid(n,vector<int>(m,0));
  int holes;
  cin >> holes;
  
  for(int i=0; i<holes; i++) {
    int x,y;
    cin >> x >> y;
    x--;
    y--;
    grid[x][y] = 1;
  }
  
  // prefix sm on 2d matrix
  for(int i=0; i<n; i++) {
    for(int j=1; j<m; j++) {
      grid[i][j] += grid[i][j-1];
    }
  }
  
  for(int j=0; j<m; j++) {
    for(int i=1; i<n; i++) {
      grid[i][j] += grid[i-1][j];
    }
  }
  
  
  int low = 1; // obvious good
  int high = min(n,m) + 1; // obvious bad
  
  int ans = 1;
  
  int xb = 1, yb = 1, xt = 1, yt = 1;
  // bottom most left and topmost right coordinate
  
  while(low <= high) {
    
    int mid = (low + high)/2;
    int val = check(mid, n, m, grid, xb, yb, xt, yt);
    
    if(val > 1) {
      high = mid - 1;
    } else {
      ans = low;
      low = mid + 1;
    }
    
  }
  
  
  cout << xb + 1 << " " << yb + 1<< " " << xt + 1<< " " << yt + 1;
  
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
