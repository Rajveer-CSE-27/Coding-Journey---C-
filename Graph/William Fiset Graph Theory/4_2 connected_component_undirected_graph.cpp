// || जय जय जय बजरंग बली ||

#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=7fujbpJ0LB4&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=5

Connected components in an undirected graph
Appraoch :: 
	Use DFS
	Make sure all nodes are labelled between [1,n] or [0,n)
	Start a dfs from every node (except if it is already visited).
		Mark all the reachable nodes as the part of same component.
		
Time :: O(V + E)
Space :: O(V)
	
	
**/

vector<vector<int>> graph;
vector<bool> visited; 


void dfs(int node) {
	visited[node] = true;
	cout << node << " ";
	
	for(int adj:graph[node]) {
		if(visited[adj] == false) {
			dfs(adj);
		}
	}
}

int main() {
	
	int n, m;
	cin >> n >> m;
	graph.resize(n+1);
	visited.resize(n+1, false);
	
	for(int i=0; i<m; i++) { // currently considering undirected graph
		int n1, n2;
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}
	
	// printing all connected components
	for(int i=1; i<=n; i++) {
		if(visited[i] == false) {
			dfs(i);
			cout << '\n';
		}
	}
	
	return 0;
}
