/**
Problem Statement : We are given an “N*M” matrix of integers.
                    We need to find a path from the top-left corner to the bottom-right corner of the matrix, 
                    such that there is a minimum cost past that we select.
                    At every cell, we can move in only two directions: right and bottom. 
                    The cost of a path is given as the sum of values of cells of the given matrix.
We need to count the total number of unique paths from the top-left corner of the maze to the bottom-right corner. 
At every cell, we can move either down or towards the right.
                    
Approach : Use recursion like previous problems on grid. It is very similar.

Time Complexity = O(2^(m+n)) because each cell we explore 2 possibilities.
Space Complexity = O(m+n) auxillary stack space.
**/

#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid, int x, int y) {
    if(x == 0 and y == 0) {
        return grid[x][y];
    }
    if(x == 0) {
        return grid[x][y] + minPathSum(grid,x,y-1);
    }
    if(y == 0) {
        return grid[x][y] + minPathSum(grid,x-1,y);
    }
    
    return grid[x][y] + min(minPathSum(grid,x-1,y),minPathSum(grid,x,y-1));
}

int main() {
    
    int m,n;
    cin >> m >> n;
    
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }
    
    int ans = minPathSum(grid, m-1, n-1);
    cout << ans;
    return 0;
}
