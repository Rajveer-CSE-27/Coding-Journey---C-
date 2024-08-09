// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=lyw4FaxrwHg&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=20
https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/
https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

Bellman Ford :: 
	SSSP algorithm
	Time complexity :: O(EV) as we relax each edge (V-1) times
	
	Dijkstra's algorithm can fail when the graph has negative edge weights. This is when Bellman Ford becomes really handy because it can be used to detect negative cycles and determine where they occur.	 
	NOTE :: Dijkstra will only fail due to negative cycles and not with negative edge weights.
	

Steps ;: 
	Let E = number of edges
	V = number of nodes
	S = source node
	D = be an array of size V that tracks the best distance from S to each node
	
	1. Set every vertex in D to inf
	2. set D[S] = 0
	3. relax each edge V-1 times.
	
	
	Now at the end if you want to find nodes that are part of negative cycles
	Repeat step 3 that is relax each edge V-1 times.
	The nodes whose D[i] still updates i.e gets lowered will be a part of negative cycle.

Q-> Why relax V-1 times ?
	In the worst-case scenario, a shortest path between two vertices can have at most N-1 edges.
	By relaxing edges N-1 times, the Bellman-Ford algorithm ensures that the distance estimates for all vertices have been updated to their optimal values.
	That is the info of reducing the shortest distance of one node has travelled to all the nodes in graph.
	Relaxing edges N-1 times in the Bellman-Ford algorithm guarantees that the algorithm has explored all possible paths of length up to N-1, which is the maximum possible length of a shortest path in a graph with N vertices. 
	
Q-> Why Does the Reduction of Distance in the N’th Relaxation Indicates the Existence of a Negative Cycle?
	achieving the single source shortest paths to all other nodes takes N-1 relaxations. 
	If the N’th relaxation further reduces the shortest distance for any node, it implies that a certain edge with negative weight has been traversed once more.
	And hence containing a negative cycle.

**/

vector<vector<pair<int,int>>> graph; 

void bellman_ford(int source, int n) {
	
	
	vector<int> dist(n, INT_MAX);
	dist[source] = 0;
	
	for(int t=0; t<n-1; t++) {
		
		// relax each edge
		for(int i=0; i<n; i++) {
			for(pair<int,int> adj:graph[i]) {
				int nextNode = adj.first, weight = adj.second;
			
				if(dist[i] != INT_MAX and  dist[nextNode] > dist[i] + weight) {
					dist[nextNode] = dist[i] + weight;
				}
			}
		}
	}
	
	// repeat V-1 times to catch the nodes that are in negative cycles
	for(int t=0; t<n-1; t++) {
		
		for(int i=0; i<n; i++) {
			for(pair<int,int> adj:graph[i]) {
				int nextNode = adj.first, weight = adj.second;
				
				if(dist[i] != INT_MAX and dist[nextNode] > dist[i] + weight) {
					dist[nextNode] = INT_MIN; // this node is in negative cycle
				}
			}
		}
	}
	
	// you can also keep parent array to get the actual shortest path
	for(int d:dist) {
		cout << d << " ";
	}
}

int main(){
	
	int n,m;
	cin >> n >> m;
	
	graph.resize(n); // 0based indexing
	for(int i=0; i<m; i++) {
		int n1,n2,w;
		cin >> n1 >> n2 >> w;
		graph[n1].push_back({n2,w});
	}
	
	bellman_ford(0, n);
    return 0;
}
