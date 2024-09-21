// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=pSqmAO-m7Lk&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=18
https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

Dijkstra's algorithm is a Single Source Shortest Path (SSSP) algorithm for graphs with non-negative edge weights.
Time complexity is :: O(Elog(V)).

We will maintain a priority queue for getting the smallest element each time. {that is why we do not take negative edges in this algorithm}

Lazy Dijkstra :: 
	It is the simple Dijsktra from a node.
	It is called lazy because we go on storing the values that we do not need in the priority queue and later pop it.

	Time :: O(Elog(V)).

**/

vector<vector<pair<int,int>>> graph;

void dijkstra(int source, int n) {
	
	priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
	pq.push({0,{source,-1}}); 
	// each element of pq :: {d,{i,j}} will store {value,{index, parent_of_index}}
	
	vector<int> parent(n,-1); // to keep the track of shortest path from source node to current node.

	
	vector<int> dist(n, INT_MAX); // shortest distance of current node from source node
	dist[source] = 0;
	
	
	while(!pq.empty()) {
		pair<int, pair<int,int>> pr = pq.top();
		pq.pop();

		int node = pr.second.first;
		parent[node] = pr.second.second;
		
		for(pair<int,int> adj: graph[node]) {
			int next = adj.first, d = adj.second;
			d += dist[node];

			if(dist[next] > d) {
				dist[next] = d;
				pq.push({d,{next, node}});
			}
		}
	}
	
	cout << "Source node : " << source << '\n';
	for(int i=0; i<n; i++) {
		cout << "Current node : " << i << " ";
		cout << "Shortest distance from source : " << dist[i] << '\n';
		cout << "Path : ";
		int curr = i;
		vector<int> path;
		while(curr != -1) {
			path.push_back(curr);
			curr = parent[curr];
		}
		for(int j=path.size()-1; j>=0; j--) {
			cout << path[j] << " "; 
		}
		cout << '\n';
	}
	
}

int main(){
	
	int n,m;
	cin >> n >> m;
	graph.resize(n); // 0 based indexing
	for(int i=0; i<m; i++) {
		int n1,n2,w;
		cin >> n1 >> n2 >> w;
		graph[n1].push_back({n2,w});
	}
	
	dijkstra(0,n); // that is we want shortest path from sourde node 0.
	
    return 0;
}
