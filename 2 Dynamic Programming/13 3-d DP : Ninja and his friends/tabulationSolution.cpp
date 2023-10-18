/**
Problem Statement : We are given an ‘N*M’ matrix. 
					Every cell of the matrix has some chocolates on it, mat[i][j] gives us the number of chocolates. 
					We have two friends ‘Alice’ and ‘Bob’. initially, Alice is standing on the cell(0,0) and Bob is standing on the cell(0, M-1). 
					Both of them can move only to the cells below them in these three directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).
					When Alica and Bob visit a cell, they take all the chocolates from that cell with them. 
					It can happen that they visit the same cell, in that case, the chocolates need to be considered only once.
					They cannot go out of the boundary of the given matrix, 
					we need to return the maximum number of chocolates that Bob and Alice can together collect.
                    
Approach : Using tabulation approach over memoization.
		   
Time Complexity = O(n*m*m*9) because at each row we will check 3 different possibilities 3 times.
Space Complexity = O(n*m*m) dp space.
**/

#include <bits/stdc++.h>
using namespace std;

int dir[] = {-1,0,1};

int main() {
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m)));
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> grid[i][j];
		}
	}
	
	// the base case i.e of last row
	for(int j1 = 0; j1 < m; j1++) {
		for(int j2 = 0; j2 < m; j2++) {
			int value;
			if(j1 == j2) {
				value = grid[n-1][j1];
			} else {
				value = grid[n-1][j1] + grid[n-1][j2];
			}
			
			dp[n-1][j1][j2] = value;
		}
	}
	
	// rest all other possible cases
	for(int currentRow = n-2; currentRow >= 0; currentRow--) {
		
		for(int j1=0; j1 < m; j1++) {
			for(int j2=0; j2<m; j2++) {
				int maxi = INT_MIN;
				for(int it1:dir) {
					for(int it2:dir) {
						int value;
						if(j1 == j2) {
							value = grid[currentRow][j1];
						} else {
							value = grid[currentRow][j1] + grid[currentRow][j2];
						}
				
						if(j1 + it1 >= 0 and j1 + it1 < m and j2+it2 >=0 and j2+it2 < m) {
							value += dp[currentRow + 1][j1+it1][j2+it2];
						} else {
							value += INT_MIN;
						}
						
						maxi = max(maxi, value);
					}
				}
				dp[currentRow][j1][j2] = maxi;
			}
		}
	}
	
	cout << dp[0][0][m-1] << '\n';
	
	return 0;
}
