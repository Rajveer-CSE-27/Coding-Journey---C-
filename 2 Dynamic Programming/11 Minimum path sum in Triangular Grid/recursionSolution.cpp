/**
Problem Statement : We are given a Triangular matrix. 
					We need to find the minimum path sum from the first row to the last row.
					At every cell we can move in only two directions: 
					either to the bottom cell (↓) or to the bottom-right cell(↘)
                    
Approach : Use recursion like previous problems on grid. But this time we start from 1st cell of 1st row.
		   Recurrence relation : f(i,j) = value[i][j] + min(f(i+1,j) + f(i,j+1))
		   where i = row number and j = column number.

Time Complexity = O(2^(n)) because each row we explore 2 possibilities.
Space Complexity = O(n) auxillary stack space.
**/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& triangle, int currentRow, int currentCol, int rows) {
	if(currentRow == rows) {
		return 0;
	}
	int ans1 = triangle[currentRow][currentCol] + solve(triangle, currentRow + 1, currentCol, rows);
	int ans2 = triangle[currentRow][currentCol] + solve(triangle, currentRow + 1, currentCol + 1, rows);
	
	return min(ans1, ans2);
}

int main() {
	
	int rows;
	cin >> rows;
	vector<vector<int>> triangle;
	int j = 0;
	for(int i=0; i<rows; i++) {
		j++;
		int k = j;
		vector<int> temp;
		while(k--) {
			int x;
			cin >> x;
			temp.push_back(x);
		}
		triangle.push_back(temp);
	}
	
	int minSum = solve(triangle, 0, 0, rows);
	cout << minSum << '\n';
	
	return 0;
}
