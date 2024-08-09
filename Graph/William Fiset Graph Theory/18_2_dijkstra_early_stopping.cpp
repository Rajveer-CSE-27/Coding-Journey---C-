// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=pSqmAO-m7Lk&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=18

Dijkstra algorithm Early stopping :: 
	This is an optimization to classic Dijkstra.
	If we only want shortest path from node n1 to n2.
	Then while running the dijkstra if we pop the node n2 from the priority queue for first time, this means that this would be the shortest ditance for n2 and any occurence of n2 in future will only result in longer distances.
	This is because in dijkstra we greedily pick the shortest distance node from current position and if we pick n2 for first this means this would be shortest distance till n2.


**/

vector<vector<pair<int,int>>> graph;

void dijkstra(int source, int destination, int n) {
	
	priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
	pq.push({0,{source,-1}}); 
	// each element of pq :: {d,{i,j}} will store {value,{index, parent_of_index}}
	
	vector<int> parent(n,-1); // to keep the track of shortest path from source node to current node.

	
	vector<int> dist(n, INT_MAX); // shortest distance of current node from source node
	
	while(!pq.empty()) {
		pair<int,pair<int,int>> pr = pq.top();
		pq.pop();
		
		int curr_dist = pr.first, node = pr.second.first, par = pr.second.second;
		int total_distance_from_source = (par == -1) ? 0 : dist[par];
		
		if(dist[node] < curr_dist + total_distance_from_source) { // we already have a better smaller distance for current node
			continue;
		}
		
		dist[node] = curr_dist + total_distance_from_source;
		parent[node] = par;
		
		if(node == destination) {
			// early stopping
			break;
		}
		
		for(pair<int,int> adj:graph[node]) {
			pq.push({adj.second, {adj.first, node}});
		}
		 
	}
	
	cout << "Source node : " << source << " " << "Destination node : " << destination << '\n';
	
	int curr = destination;
	vector<int> path;
	while(curr != -1) {
		path.push_back(curr);
		curr = parent[curr];
	}
	for(int j=path.size()-1; j>=0; j--) {
		cout << path[j] << " "; 
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
	
	dijkstra(0, 3, n); // that is we want shortest path from sourde node 0.
	
    return 0;
}
