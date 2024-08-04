// || जय जय जय बजरंग बली ||

#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=oDqjPvD54Ss&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=5

Shortest path between 2 nodes in unweighted graph.
Approach :: 
	Use bfs  from source node.
	Keep on storing the prev node for each node.
	When you reach destination, just iterate backwards to source node	
**/

vector<vector<int>> graph;
vector<bool> visited; 

void shortest_path(int src, int destination) {
	
	//bfs from node
	vector<int> parent(graph.size() + 1);
	queue<int> q;
	q.push(src);
	visited[src] = true;
	parent[src] = -1;
	
	bool flag = false;
	while(!q.empty() and flag == false) {
		int m = q.size();
		
		while(m--) {
			int node = q.front();
			q.pop();
			
			if(node == destination) {
				flag = true;
				break;
			}
			
			for(int adj:graph[node]) {
				if(visited[adj] == false) {
					parent[adj] = node;
					visited[adj] = true;
					q.push(adj);
				}
			}
		}
	}
	
	vector<int> path;
	int curr = destination, prev = parent[destination];
	
	while(prev != -1) {
		path.push_back(curr);
		curr = prev;
		prev = parent[curr];
	}
	
	reverse(path.begin(), path.end());
	for(int i:path) {
		cout << i << " ";
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
	
	int src, dest;
	cin >> src >> dest;
	
	shortest_path(src, dest);
	
	return 0;
}
