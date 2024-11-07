#include <bits/stdc++.h>
using namespace std;


int mn;
int n,m;

void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis, int cost) {
    
    if(grid[i][j] == 3) {
        if(mn > cost) {
            mn = cost;
        }
        return;
    }
    
    vis[i][j] = true;
    
    // horizontal movement
    if(j+1 < m and grid[i][j+1] != 0 and vis[i][j+1] == false) {
        dfs(i,j+1,grid,vis,cost);
    }
    if(j-1 >= 0 and grid[i][j-1] != 0 and vis[i][j-1] == false) {
        dfs(i,j-1,grid,vis,cost);
    }
    
    // vertical movement
    int ii = i - 1;
    while(ii >= 0 and grid[ii][j] == 0) {
        ii--;
    }
    
    if(ii >= 0 and grid[ii][j] != 0 and vis[ii][j] == false) {
        
        dfs(ii,j,grid,vis,max(cost, i - ii));
        
    }
    
    ii = i + 1;
    while(ii < n and grid[ii][j] == 0) {
        ii++;
    }
    
    if(ii < n and grid[ii][j] != 0 and vis[ii][j] == false) {
        dfs(ii,j,grid,vis,max(cost, ii - i));
    }
    
    
    vis[i][j] = false;
    
}

int main() {
    
    cin >> n >> m;
    
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }
    
    
    // start at {n-1,0}
    mn = INT_MAX;
    
    vector<vector<bool>> vis(n, vector<bool>(m,false));
    
    dfs(n-1,0,grid,vis,0);
    
    cout << mn;
    
    return 0;
}
