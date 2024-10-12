#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;

/**
https://github.com/s-kachroo/SamsungPractice/blob/master/mr%20lee.cpp

TSP
Solve it either using recursion :: O(n!)
or using dp - bitmasking :: O(n*n*2^n)

Here some cities do not have path between them so handle that condition as well

**/

int fun(int mask, int curr, vector<vector<int>>& graph, vector<vector<int>>& dp, int& n) {
	
	int endMask = (1<<n) - 1;
	if(mask == endMask) {
		// visited all cities
		if(graph[curr][0] != 0) {
			return graph[curr][0];
		}
		return N;
	}
	
	if(dp[mask][curr] != -1) {
		return dp[mask][curr];
	}
	
	int ans = N;
	
	for(int city = 0; city < n; city++) {
		
		if((mask & (1<<city)) == 0) {
			// not visited
			if(graph[curr][city] != 0) {
				int temp = graph[curr][city] + fun((mask | (1<<city)), city, graph, dp, n);
				ans = min(ans, temp);
			}
		} 
	}
	
	return dp[mask][curr] = ans;
 	
}

void solve() {
	int n;
	cin >> n;
	
	vector<vector<int>> graph(n, vector<int>(n));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> graph[i][j];
		}
	}
	
	// start position = 0;
	vector<vector<int>> dp((1<<n) + 5, vector<int>(n, -1));
	
	// dp[i][j] = visited cities mask = i and current city = j
	
	int ans = fun(1, 0, graph, dp, n);
	if(ans >= N) {
		cout << -1;
	} else {
		cout << ans;
	}
}

int main() {   
	
	int tc;
	cin >> tc;
	
	while(tc--) {
		solve();
		cout << '\n';
	}
 	
    return 0;
}
