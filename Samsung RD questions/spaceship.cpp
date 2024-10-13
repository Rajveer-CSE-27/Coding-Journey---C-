#include <bits/stdc++.h>
using namespace std;
#define ll long long


/**
https://github.com/s-kachroo/SamsungPractice/blob/master/spaceship%20bomb.cpp

Recursion

**/

int n;
vector<vector<int>> matrix;
int ans;

void fun(int j, int nextRow, bool bombUsed, int cnt, int coins) {
	
	ans = max(ans, coins);
	// because we need to find maximum coins at any time
	
	if(nextRow == -1) {
		return;
	}
	
	for(int k=-1; k<=1; k++) {
		int j1 = j + k;
		
		if(j1 >= 0 and j1 < 5) {
			
			if(matrix[nextRow][j1] == 1) {
				// take the coin and move ahead
				fun(j1, nextRow - 1, bombUsed, cnt-1, coins+1);
				
			} else if(matrix[nextRow][j1] == 0) {
				// move ahead
				fun(j1, nextRow - 1, bombUsed, cnt - 1, coins);
				
			} else {
				
				// try all possibilities.
				
				if(bombUsed == false) {
					// using bomb
					
					fun(j1, nextRow - 1, true, 4, coins);
				}
				
				if(cnt > 0) {
					// using effect of bomb that was used earlier
					
					fun(j1, nextRow - 1, bombUsed, cnt-1, coins);
				}
				
				if(coins > 0) {
					
					// using coins to move ahead
					fun(j1, nextRow - 1, bombUsed, cnt - 1, coins);
				}
				
				if(bombUsed == true and cnt <= 0 and coins == 0) {
					// not able to progress.  Hence return
					ans = max(ans, coins);
					return;
				}
				
			}
			
		}
		
	}
	
	
}


int main() {   
	
	cin >> n;
	matrix.resize(n, vector<int>(5));
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<5; j++) {
			cin >> matrix[i][j];
		}
	}
	
	
	ans = -1;
	fun(2, n-1, false, 0, 0);
	
	if(ans == 0) {
		ans = -1;
	}
	
	cout << ans;
 	
    return 0;
}
