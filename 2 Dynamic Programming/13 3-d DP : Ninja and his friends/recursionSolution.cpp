/**
Problem Statement : We are given an ‘N*M’ matrix. 
					Every cell of the matrix has some chocolates on it, mat[i][j] gives us the number of chocolates. 
					We have two friends ‘Alice’ and ‘Bob’. initially, Alice is standing on the cell(0,0) and Bob is standing on the cell(0, M-1). 
					Both of them can move only to the cells below them in these three directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).
					When Alica and Bob visit a cell, they take all the chocolates from that cell with them. 
					It can happen that they visit the same cell, in that case, the chocolates need to be considered only once.
					They cannot go out of the boundary of the given matrix, 
					we need to return the maximum number of chocolates that Bob and Alice can together collect.
                    
Approach : Recursion approach. 
		   Recurrence relation at any cell: F(i,j1,j2) = value[i][j1] + value[i][j2] + max(F(i+1,j1-1,j2-1), F(i+1,j1-1,j2), F(i+1,j1-1,j2+1), F(i+1,j1,j2-1), F(i+1,j1,j2), F(i+1,j1,j2+1), F(i+1,j1+1,j2-1), F(i+1,j1+1,j2), F(i+1,j1+1,j2+1)). 
		   Hence we need to explore all 9 combos.
		   We need to keep in mind that any time if both of them pickup from same cell then value must be only added once
		   
Time Complexity = O(9^(n)) because at each row we need to explore 9 possibilities.
Space Complexity = O(n) auxillary stack space.
**/

#include <bits/stdc++.h>
using namespace std;

int dir[] = {-1,0,1};

int solve(vector<vector<int>>& grid, int currentRow, int aliceCol, int bobCol, int n, int m) {
	
	// base case 1. We reach the last row
	if(currentRow == n-1) {
		if(aliceCol == bobCol) {
			return grid[currentRow][aliceCol];
		} 
		return grid[currentRow][aliceCol] + grid[currentRow][bobCol];
	}
	
	// base case 2. If we go out of bound.
	if(aliceCol == -1 or aliceCol == m or bobCol == -1 or bobCol == m) {
		return INT_MIN;
	}
	
	// this will help us to explore 9 combos.
	int maxi = INT_MIN;
	for(int it1:dir) {
		for(int it2:dir) {
			if(aliceCol == bobCol) {
				maxi = max(maxi, grid[currentRow][aliceCol] + solve(grid, currentRow + 1, aliceCol + it1, bobCol + it2, n, m));
			} else {
				maxi = max(maxi, grid[currentRow][aliceCol] + grid[currentRow][bobCol] + solve(grid, currentRow + 1, aliceCol + it1, bobCol + it2, n, m));
			}
		}
	}
	return maxi;
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
	
	cout << solve(grid, 0, 0, m-1, n, m);
	
	return 0;
}
