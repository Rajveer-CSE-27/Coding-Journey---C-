// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define int long long


/**

https://www.youtube.com/watch?v=4NQ3HnhyNfQ&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=22
https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

Floyd Warshall algorithm :: 
	All pairs shortest path algo.
	Time Complexity :: O(V^3) hence ideal for graph with <= 100 nodes 
	
	Best representation of graph is using 2D adjacency matrix.
	A[i][j] = edge weight from node i to node j
	assume that A[i][i] = 0 for all i
	if no edge exist from i to j then A[i][j] = inf
	
	Main idea behind the Floyd-Warshall algorithm is to gradually build up all intermediate routes between nodes i and j
	to find the optimal path.
	
	The main idea to use here is to check for all node pairs(i,j) check the length of the path if path passes through node k for all k (1,2,3,.....n).
	
	Reccurence :: 
		dp[i][j] = A[i][j] if (k == 0) that is no intermediatery node.
		
		for k=1 to n 
		
			for all pairs (i,j)
			dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])
			
		
		After all iterations :: dp[i][j] will store shortest path length from node i to j
	
	
	For constructing the shortest path from any node i to node j
		Construct a matrix Next[n][n] which will keep location of Next best node when going from node i to j
		Along with dp[i][j] also go on updating Next[i][j] when required.
		
		
		
	Checking for negative cycles.
		That is checking if shortest path between node i to j is affected by a negative cycle or not.
		
		Rerun the floyd warshall once more. If dp[i][j] gets updated at any point then dp[i][j] = -inf hence path from i to j is affected by megative cycle.
		Also update Next[i][j] = -1 indicating that path contains negative cycle.
			
**/


signed main(){
	
	
	// use long long if needed
	
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
	vector<vector<int>> Next(n+1, vector<int>(n+1, -1));
	
	for(int i=0; i<m; i++) {
		int n1,n2,w;
		cin >> n1 >> n2 >> w;
		
		dp[n1][n2] = w;
		Next[n1][n2] = n2;
	}
	 
	for(int i=1; i<=n; i++) {
		dp[i][i] = 0;
		Next[i][i] = i;
	}
	
	for(int k=1; k<=n; k++) {
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(dp[i][j] > dp[i][k] + dp[k][j] and dp[i][k] != INT_MAX and dp[k][j] != INT_MAX) {
					dp[i][j] = dp[i][k] + dp[k][j];
					
					// till now best path from i to j goes through k
					// has Next[i][j] = Next best node when going from i to k
					Next[i][j] = Next[i][k];
				}
			}
		}
		
	}
	
	// detect and propagate negative cycles among the entire graph
	
	for(int k=1; k<=n; k++) {
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(dp[i][j] > dp[i][k] + dp[k][j] and dp[i][k] != INT_MAX and dp[k][j] != INT_MAX) {
					
					// path from i to j is one or the other way affected by negative cycles
					dp[i][j] = INT_MIN;
					Next[i][j] = -1;
				}
			}
		}
	}
	
	
	// shortest path for all nodes
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << '\n';
	}
	
	// next nodes for all paths (i to j)
	
	cout << '\n';
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cout << Next[i][j] << " ";
		}
		cout << '\n';
	}
    return 0;
}
