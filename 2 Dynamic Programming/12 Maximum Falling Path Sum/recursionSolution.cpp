/**
Problem Statement : We are given an ‘N*M’ matrix. 
					We need to find the maximum path sum from any cell of the first row to any cell of the last row.
					At every cell we can move in three directions: 
					to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).
                    
Approach : Using recursion. 
		   Recurrence relation at any cell :: F(i,j) = value[i][j] + max(F(i+1,j-1), F(i+1,j), F(i+1,j+1))
		   We need to calculate this for all the cell and the cell of the first row which has max value will be the answer.

Time Complexity = O(m * 3^(n)) because each cell of first row we explore (3^(n)) paths.
Space Complexity = O(n) auxillary stack space.
**/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& grid, int currentRow, int currentCol, int rows, int cols) {
	
	if(currentRow == rows) {
		return 0;
	}
	if(currentCol == -1 or currentCol == cols) {
		return 0;
	}
	
	int direction1 = solve(grid, currentRow + 1, currentCol - 1, rows, cols);
	int direction2 = solve(grid, currentRow + 1, currentCol, rows, cols);
	int direction3 = solve(grid, currentRow + 1, currentCol + 1, rows, cols);
	
	int ans = grid[currentRow][currentCol] + max(direction1, max(direction2, direction3));
	return ans;  
}

int main() {
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> grid[i][j];
		}
	}
	
	int maxPathSum = INT_MIN;
	for(int j=0; j<m; j++) {
		maxPathSum = max(maxPathSum, solve(grid, 0, j, n, m));
	}
	
	cout << maxPathSum << '\n';
	return 0;
}
