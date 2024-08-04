// || जय जय जय बजरंग बली ||

#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=oDqjPvD54Ss&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=5

Shortest path in unweighted graph ::
	
Approach :: 
	Do BFS from source node. Also keep on storing previous node/ parent for each visited node.
	If you reach the destination node construct the path using information of parent nodes, in this BFS traversal.
	
**/

vector<vector<int>> graph;
vector<bool> visited; 

void bfs(int node) {
	// bfs starting from node 1
	queue<int> q;
	q.push(node);
	visited[node] = true;
	
	while(!q.empty()) {
		int m = q.size();
		while(m--) {
			int tempNode = q.front();
			q.pop();
		
			cout << tempNode << " ";
			for(int adj:graph[node]) {
				if(visited[adj] == false) {
					visited[adj] = true;
					q.push(adj);
				}
			}
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
	
	bfs(1);
	
	return 0;
}
