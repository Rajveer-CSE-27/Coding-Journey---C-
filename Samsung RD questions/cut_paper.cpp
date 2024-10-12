#include <bits/stdc++.h>
using namespace std;
#define ll long long


/**
https://github.com/s-kachroo/SamsungPractice/blob/master/Two%20Problems%20Mixed.cpp

classic recursion
constraints are small and such that any cut will lead us to a square.

Use prefix sm of matrix to calculate number of blues (1's) in each square in O(1) time.

Dhyan do what you need to output.

**/

void fun(int i1, int i2, int j1, int j2, int& white, int& blue, vector<vector<int>>& pref) {
	
	// checking whether all cells of current square are painted same 
	
	int cnt = pref[i2][j2];
	if(i1 - 1 >= 0) {
		cnt -= pref[i1 - 1][j2];
	}
	if(j1 - 1 >= 0) {
		cnt -= pref[i2][j1 - 1];
	}
	if(i1 - 1 >= 0 and j1 - 1 >= 0) {
		cnt += pref[i1 - 1][j1 - 1];
	}
	
	int total = (i2 - i1 + 1) * (j2 - j1 + 1);
	
	if(cnt == 0) {
		// all white
		white++;
		
		return;
	}
	if(cnt == total) {
		// all blue
		blue++;
		return;
	}
	
	// cut
	int midi = (i1 + i2)/2;
	int midj = (j1 + j2)/2;
	
	fun(i1, midi, j1, midj, white, blue, pref);
	fun(midi + 1, i2, j1, midj, white, blue, pref);
	fun(i1, midi, midj + 1, j2, white, blue, pref);
	fun(midi + 1, i2, midj + 1, j2, white, blue, pref);
}

void solve() {
	int n;
	cin >> n;
	vector<vector<char>> matrix(n, vector<char>(n));
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> matrix[i][j];
		}
	}
	
	vector<vector<int>> pref(n, vector<int>(n,0));
	// row wise first
	for(int i=0; i<n; i++) {
		int cnt = 0;
		for(int j=0; j<n; j++) {
			if(matrix[i][j] == '1') {
				cnt++;
			}
			pref[i][j] = cnt;
		}
	}
	
	// column wise now
	for(int j=0; j<n; j++) {
		for(int i=1; i<n; i++) {
			pref[i][j] += pref[i-1][j];
		}
	}
	
	int white = 0, blue = 0;
	
	fun(0,n-1,0,n-1, white, blue, pref);
	
	
	cout << white << " " << blue;
}

int main() {   

	int tc;
	cin >> tc;
	while(tc--) {
		
		solve();
		cout << "\n";
	}
 	
    return 0;
}
