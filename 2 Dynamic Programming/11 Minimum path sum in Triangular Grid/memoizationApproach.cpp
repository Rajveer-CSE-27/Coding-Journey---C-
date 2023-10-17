/**
Problem Statement : We are given a Triangular matrix. 
					We need to find the minimum path sum from the first row to the last row.
					At every cell we can move in only two directions: 
					either to the bottom cell (↓) or to the bottom-right cell(↘)
                    
Approach : Using memoization to save the time because we having overlapping subproblems.

Time Complexity = O(n * n) because each cell is explored exactly once.
Space Complexity = O(n * n) dp space + O(n) auxillary stack space.
**/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& triangle, int currentRow, int currentCol, int rows, vector<vector<int>>& dp) {
	if(currentRow == rows) {
		return 0;
	}
	if(dp[currentRow][currentCol] != INT_MIN) {
		return dp[currentRow][currentCol];
	}
	
	int ans1 = triangle[currentRow][currentCol] + solve(triangle, currentRow + 1, currentCol, rows, dp);
	int ans2 = triangle[currentRow][currentCol] + solve(triangle, currentRow + 1, currentCol + 1, rows, dp);
	
	return dp[currentRow][currentCol] = min(ans1, ans2);
}

int main() {
	
	int rows;
	cin >> rows;
	vector<vector<int>> triangle, dp;
	int j = 0;
	for(int i=0; i<rows; i++) {
		j++;
		int k = j;
		vector<int> temp, tempDp;
		while(k--) {
			int x;
			cin >> x;
			temp.push_back(x);
			tempDp.push_back(INT_MIN);
		}
		triangle.push_back(temp);
		dp.push_back(tempDp);
	}
	
	
	int minSum = solve(triangle, 0, 0, rows, dp);
	cout << minSum << '\n';
	
	return 0;
}
