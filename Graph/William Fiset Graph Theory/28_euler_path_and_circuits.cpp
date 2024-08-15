// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long


/**
https://www.youtube.com/watch?v=xR4sGgwtR2I&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=27

Eulerian Path :: An Eulerian Path (or Eulerian Trail) is a path of edges that visits all the edges in a graph
				 exactly once.
				 
Eulerian circuit :: Eulerian circuit (or Eulerian cycle) is an Eulerian path which starts and ends on the same vertex.

NOTE :: for an eulerian path or circuit to exist, the graph must be connected.
		If not connected, there does not exist any eulerian path or circuit.
		
		Edge case :: if a graph has multiple components but all the edges lies in a single component and rest of the components are just vertices with no edges,
					 then there can exist a valid eulerian path or circuit.
		
For undirected graph :: 
		
		Eulerian circuit exists if every vertex has even degree.
		
		Eulerian path exists if :: 
			-> Every vertex has even degree  OR 
			-> Exactly 2 vertex can have odd degree. (These 2 vertices can be thought of start and end of eulerian path).

For directed graph :: 
		Eulerian circuit exists if every vertex has equal indegree and outdegree.
		
		Eulerian path exists if :: 
			At most one vertex has (outdegree) - (indegree) = 1  :: possible start node
			and at most one vertex has (indegree) - (outdegree) = 1 :: possible end node
			and all other vertices have indegree = outdegree.
		

https://www.youtube.com/watch?v=8MpoO2zA2l4&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=28
Hierholzer's algorithm to find eulerian path / eulerian circuit.
https://www.geeksforgeeks.org/problems/euler-circuit-and-path/1

Approach :: 
	-> First check whether a valid eulerian path exists or not.
			Check the above by computing indegree and outdegree for each node {whether graph is directed or undirected}.
			Check the conditions mentioned above.
	
	-> If the graph can have a valid eulerian circuit then, 
	-> Select a start node to start eulerian path. Handle the case of singleton vertex {vertex with 0 edges}.
	-> Start dfs at start node.
	-> For each node visit all the edges with dfs and go on decrementing the outdegree.
	-> When outdegree = 0 for a vertex then add that vertex to front of euler tour.
	
	-> Check if size of tour == e + 1. Then valid euler tour.
	-> if first value of vertex in tour == last then it is valid euler circuit.

Time :: O(E) becuase we go through every edge once.
**/

vector<vector<int>> graph;
vector<int> inDegree;
vector<int> outDegree;


bool hasEulerianPath() {
	int startNodeCnt = 0, endNodeCnt = 0;
	int n = graph.size();
	
	for(int i=0; i<n; i++) {
		if(abs(outDegree[i] - inDegree[i]) > 1) {
			return false;
		}
		
		if(outDegree[i] - inDegree[i] == 1) {
			startNodeCnt++;
		} else if(inDegree[i] - outDegree[i] == 1) {
			endNodeCnt++;
		}
		
	}
	
	if(startNodeCnt == 0 and endNodeCnt == 0) {
		return true;
	}
	if(startNodeCnt == 1 and endNodeCnt == 1) {
		return true;
	}
	return false;
}

int findStartNode() {
	
	int n = graph.size();
	
	for(int i=0; i<n; i++) {
		if(outDegree[i] - inDegree[i] == 1) {
			// this is a unique start node i graph
			return i;
		}
	}
	
	// if all nodes have same outDegree and inDegree
	int start;
	for(int i=0; i<n; i++) {
		if(outDegree[i] > 0) { // handling the case of singleton node.
			// atleast 1 outdegree wala can be a start node now.
			start = i;
		}
	}
	
	return start;
}

void dfs(int node, vector<int>& eulerPath) {
	
	while(outDegree[node] != 0) {
		
		outDegree[node]--;
		int nextNode = graph[node][outDegree[node]];
		dfs(nextNode, eulerPath);
		
	}
	
	// once all edges from a node visited, add it to euler path
	eulerPath.push_back(node);
}

void findEulerianPath(int m) {
	
	if(hasEulerianPath() == false) {
		cout << "No valid euler path exists.\n";
		return;
	}
	
	vector<int> eulerPath;
	int startNode = findStartNode();
	
	dfs(startNode, eulerPath);
	
	reverse(eulerPath.begin(), eulerPath.end());
	// becuase we are adding the parent nodes after coming back from child nodes in recursion
	
	if(eulerPath.size() != m+1) {
		cout << "No valid euler path exists.\n";
		return;
	}
	
	// if first node == last node then this is a valid eulertian circuit.
	for(int node:eulerPath) {
		cout << node << " ";
	}
	
}

int main() {
	
	int n,m;
	cin >> n >> m;
	
	graph.resize(n); // 0 based
	
	for(int i=0; i<m; i++) {
		int n1,n2;
		cin >> n1 >> n2;
		graph[n1].push_back(n2); // we are taking directed graph. 
		
	}
	
	// computing in and out degree for each vertex
	inDegree.resize(n,0);
	outDegree.resize(n,0);
	
	for(int i=0; i<n; i++) {
		for(int adj:graph[i]) {
			outDegree[i]++;
			inDegree[adj]++;
		}
	}
	
	findEulerianPath(m);
	return 0;
}
