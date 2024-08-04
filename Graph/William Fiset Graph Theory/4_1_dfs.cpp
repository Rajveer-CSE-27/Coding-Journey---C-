// || जय जय जय बजरंग बली ||

#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
DFS ::
	Time :: O(V + E)
	Space :: O(V)
	
Approach :: 
	Start dfs at a node
	Pick an outgoing edge from current node.
	Make sure you do not re-visit the visited nodes.
	Backtrack when dead end is reached
	
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
	
	dfs(1); // dfs traversal starting from node 1
	
	return 0;
}
