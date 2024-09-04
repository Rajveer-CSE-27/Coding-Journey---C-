// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=BtdgAys4yMk&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=14
https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=replace-os-with-xs

Components find karo that consist of only O.
Now if any element of component is at edge then that whole component cannont be converted to X
Else all elements of component will be converted to X.

Visit each cell exactly once.
Time :: O(n*m)
Space :: O(n*m)

**/

class Solution{
public:
    
    vector<pair<int,int>> component;
    vector<vector<bool>> vis;
    
    int dirx[4] = {0,0,1,-1};
    int diry[4] = {1,-1,0,0};
    
    void dfs(int i, int j, int& n, int& m, vector<vector<char>>& mat, bool& flag) {
        component.push_back({i,j});
        vis[i][j] = true;
        if(i == 0 or i == n-1 or j == 0 or j == m-1) {
            flag = false;
        }
        
        for(int k=0; k<4; k++) {
            int x = i + dirx[k], y = j + diry[k];
            if(x < n and y < m and x >=0 and y >= 0 and mat[x][y] == 'O' and vis[x][y] == false) {
                dfs(x,y,n,m,mat,flag);
            }
        }
        
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<char>> ans = mat;
        vis.resize(n, vector<bool>(m, false));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 'O' and vis[i][j] == false) {
                    component.clear();
                    bool flag = true;
                    dfs(i,j,n,m,mat,flag);
                    
                    if(flag == true) {
                        for(pair<int,int> node:component) {
                            ans[node.first][node.second] = 'X';
                        }
                    }
                }
            }
        }
        return ans;
    }
};



int main() {
       
    return 0;
}
