// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long


/**
https://www.youtube.com/watch?v=jsmMtJpPnhU&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=30
https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1


Lazy version of Prim's algorithm for MST

	-> MST  :: Given an undirected graph with weighted edges,
			   Minimum Spanning Tree (MST) is a subset of the edges in the graph
			   which connects all vertices together (without creating any cycles) while minimizing the total edge cost.
	
	MST may not be unique. There can exists multiple MST for a single graph.
	
	-> Time complexity for lazy version of prim's :: O(elog(e))
	
	-> Approach :: maintain a priority queue that stores cost of edge.
				   At each vertex store all the edges around it in pq.
				   Use the edge having least cost.
				   Do not visit the visited node again as you might create a cycle in MST.
**/


vector<vector<pair<int,int>>> graph;
vector<bool> visited;

void dfs(int node) {
	visited[node] = true;
	for(pair<int,int> adj:graph[node]) {
		if(visited[adj.second] == false) {
			dfs(adj.second);
		}
	}
}

bool isConnected() {
	int n = graph.size();
	int components = 0;
	
	
	for(int i=0; i<n; i++) {
		if(visited[i] == false) {
			components++;
			dfs(i);
		}
	}
	
	return (components == 1);
	
	
}

void prims() {
	
	// check whether graph is connected;
	if(isConnected() == false) {
		cout << "Graph is disconnected\n";
		return;
	}
	int n = graph.size();
	visited.clear();
	visited.resize(n,false);
	
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	// each element of pq :: {cost, startNode, endNode} will represent an edge
	
	for(pair<int,int> adj:graph[0]) {
		pq.push({adj.first, 0, adj.second});
	}
	visited[0] = true;
	
	vector<pair<int,int>> mst;
	int cost_mst = 0;
	
	 
	while(!pq.empty()) {
		
		if(mst.size() == n-1) {
			break;
		}
		
		vector<int> temp = pq.top();
		pq.pop();
		
		// check. if endNode is visited or not
		int cost = temp[0], startNode = temp[1], endNode = temp[2];
		
		if(visited[endNode] == true) {
			continue;
		}
		visited[endNode] = true;
		cost_mst += cost;
		mst.push_back({startNode,endNode});
		
		
		// adding all adjacent nodes of endNode
		for(pair<int,int> adj:graph[endNode]) {
			if(visited[adj.second] == false) {
				pq.push({adj.first, endNode, adj.second});
			}
		}
		
		
	}
	
	cout << cost_mst << '\n';
	for(auto it:mst) {
		cout << it.first << " " << it.second << '\n';
	}
	
	
}

int main() {
	
	// undirected
	int n,m;
	cin >> n >> m;
	
	graph.resize(n);
	visited.resize(n,false);
	
	for(int i=0; i<m; i++) {
		int n1,n2,w;
		cin >> n1 >> n2 >> w;
		graph[n1].push_back({w,n2});
		graph[n2].push_back({w,n1});
	}
	
	prims();
	
	return 0;
}
