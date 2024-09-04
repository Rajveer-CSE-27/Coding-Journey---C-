// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=7zmgQSJghpo&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=16
https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands

Components find karo.
Then because you are doing DFS in same way for all components.
Hence for each component subtract the indices of first cell from all cells.
Hence you can now make a set to check whether all cell indices are equal.


**/


class Solution {
  public:
  
    vector<vector<bool>> vis;  
    vector<pair<int,int>> component;
  
    set<vector<pair<int,int>>> distinctComponents;
    
    
    int dirx[4] = {0,0,1,-1};
    int diry[4] = {1,-1,0,0};
    
    void dfs(int i, int j, int& n, int& m, vector<vector<int>>& grid) {
        
        vis[i][j] = true;
        component.push_back({i,j});
        
        for(int k=0; k<4; k++) {
            int x = i + dirx[k], y = j + diry[k];
        
            if(x < n and y < m and x >= 0 and y >= 0 and grid[x][y] == 1 and vis[x][y] == false) {
                dfs(x,y,n,m,grid);
            }
        }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vis.resize(n, vector<bool>(m, false));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1 and vis[i][j] == false) {
                    component.clear();
                    dfs(i,j,n,m,grid);
                    
                    int x = component[0].first, y = component[0].second;
                    for(int k = 0; k < component.size(); k++) {
                        component[k].first -= x;
                        component[k].second -= y;
                    }
                    
                    distinctComponents.insert(component);
                    
                    
                }
            }
        }
        
        return distinctComponents.size();
        
        
    }
};



int main() {
       
    return 0;
}
