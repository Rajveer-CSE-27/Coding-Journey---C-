/**
Problem Statement : We are given a Triangular matrix. 
					We need to find the minimum path sum from the first row to the last row.
					At every cell we can move in only two directions: 
					either to the bottom cell (↓) or to the bottom-right cell(↘)
                    
Approach : Saving more space and not using whole grid.

Time Complexity = O(n * n) because each cell is explored exactly once.
Space Complexity = O(n) dp space
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
	vector<int> dp = triangle[rows - 1];
	
	for(int currentRow = rows - 2; currentRow >= 0; currentRow--) {
		vector<int> tempDp;
		for(int j=0; j<currentRow + 1; j++) {
			tempDp.push_back(triangle[currentRow][j] + min(dp[j], dp[j+1]));
		}
		dp = tempDp;
	}
	
	cout << dp[0]<< '\n';
	
	return 0;
}
