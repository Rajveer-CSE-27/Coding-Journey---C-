/**
Problem Statement : We are given a Triangular matrix. 
					We need to find the minimum path sum from the first row to the last row.
					At every cell we can move in only two directions: 
					either to the bottom cell (↓) or to the bottom-right cell(↘)
                    
Approach : Using tabulation to save the space of recursion stack.

Time Complexity = O(n * n) because each cell is explored exactly once.
Space Complexity = O(n * n) dp space
**/

#include <bits/stdc++.h>
using namespace std;

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
	
	// for tabulation approach we need to start from bottom because that will be the base case.
	vector<vector<int>> dp(rows, vector<int>(rows));
	for(int j=0; j<rows; j++) {
		dp[rows-1][j] = triangle[rows-1][j];
	}
	
	int currentRow = rows - 2;
	while(currentRow >= 0) {
		for(int j=0; j<currentRow + 1; j++) {
			dp[currentRow][j] = triangle[currentRow][j] + min(dp[currentRow + 1][j], dp[currentRow + 1][j+1]);
		}
		currentRow--;
	}
	
	cout << dp[0][0] << '\n';
	
	return 0;
}
