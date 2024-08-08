// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**

https://www.youtube.com/watch?v=TXkDpqjDMHA&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=17

Single Source Shortest Path (SSSP) in DAG.

	Approach :: 
		Because its a DAG hence we can apply topological sort concept to find SSSP from a node to all other nodes in the graph.
		Form a topological sequence of the DAG using KAHN's algorithm.
		
		In the sequence any node that lies before our start node will have distance from current node = infinity as we can never reach it.
		
		Keep the distance as infinity for all nodes. And distance to current node = 0.
		First update distance to all adjacent nodes, then go to next element in topological order.
		
		Each time update the distance of adjacent nodes, if a shorter distance from root exist then keep it.
		
		Arriving at any node in topological sequence means that we have explored all possibilities to this node.
	

	THIS WILL WORK EVEN WITH NEGATIVE EDGE WEIGHTS. 
	FINDING LONGEST DISTANCE IN DAG IS EASY JUST FLIP THE SIGN OF ALL EDGE WEIGHTS AND FIND SHORTEST PATH. 
	
	FINDING LONGEST DISTANCE IN NON DAG IS NPHARD problem.
	Time :: O(V + E);
**/

vector<vector<pair<int,int>>> graph;
vector<int> indegree;
vector<int> topological_sequence;


void generate_topological_sequence() {
	
	// kahn algorithm
	
	int n = graph.size();
	queue<int> q;
	for(int i=0; i<n; i++) {
		if(indegree[i] == 0) {
			q.push(i);
		}
	}
	
	int index = 0;
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		
		topological_sequence[index] = node;
		index++;
		for(pair<int,int> adj:graph[node]) {
			indegree[adj.first]--;
			if(indegree[adj.first] == 0) {
				q.push(adj.first);
			}
		}
	}
	
}
int main(){
	
	int n,m;
	cin >> n >> m;
	
	graph.resize(n); // 0 based
	indegree.resize(n,0);
	topological_sequence.resize(n);
	
	// input m directed edges from n1 -> n2
	for(int i=0; i<m; i++) {
		int n1,n2,dist;
		cin >> n1 >> n2 >> dist;
		graph[n1].push_back({n2,dist});
		indegree[n2]++;
	}
	
	generate_topological_sequence();
	if(topological_sequence.size() != n) {
		cout << "NOT A DAG";
		return 0;
	}
	
	int startNode;
	cin >> startNode;
	
	int index = 0;
	while(index < n) {
		if(topological_sequence[index] == startNode) {
			break;
		}
		index++;
	}
	
	vector<int> shortestDistance(n,INT_MAX);
	shortestDistance[startNode] = 0;
	
	while(index < n) {
		
		int node = topological_sequence[index];
		// hence shortest distance to this node is already at it's best;
		for(pair<int,int> adj:graph[node]) {
			int nextNode = adj.first;
			int dist = shortestDistance[node] + adj.second;
			// here we are relaxing the edge :: node -> nextNode.
			shortestDistance[nextNode] = min(shortestDistance[nextNode], dist);
		}
		index++;
	}
	
	//in a nutshell we relax all the edges and get shortest distance.
	for(int ans:shortestDistance) {
		cout << ans << " ";
	}
	
    return 0;
}
