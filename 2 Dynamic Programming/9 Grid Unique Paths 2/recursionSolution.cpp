/**
Problem Statement : We are given an “N*M” Maze. The maze contains some obstacles. 
                    A cell is ‘blockage’ in the maze if its value is -1.
                    0 represents non-blockage. There is no path possible through a blocked cell.

We need to count the total number of unique paths from the top-left corner of the maze to the bottom-right corner. 
At every cell, we can move either down or towards the right.
                    
Approach : Use recursive approach like previous problem. 
           Recurrence : F(i,j) = F(i-1,j) + F(i,j-1).
           Just handle the case of blocked cell. And it's neighbours.

Time Complexity = O(2^(m+n)) because for each cell we will be exploring 2 paths.
Space Complexity = O(m+n) : auxillary stack space.
**/

#include <bits/stdc++.h>
using namespace std;

int uniquePaths(vector<vector<int>> maze, int x, int y) {
    if(maze[x][y] == -1) {
        return 0;
    }
    if(x == 0 or y == 0) {
        return 1;
    }
    
    return uniquePaths(maze,x-1,y) + uniquePaths(maze,x,y-1);
}

int main() {
    
    int m,n;
    cin >> m >> n;
    
    vector<vector<int>> maze(m, vector<int>(n));
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> maze[i][j];
        }
    }
    
    int ans = uniquePaths(maze, m-1, n-1);
    cout << ans;
    return 0;
}
