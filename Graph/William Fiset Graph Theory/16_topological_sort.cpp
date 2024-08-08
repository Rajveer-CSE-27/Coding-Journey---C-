// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**

https://www.youtube.com/watch?v=cIBFEhD77b4&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=16
https://leetcode.com/problems/course-schedule-ii/submissions/1348743805/
Topological sort using Kahn algorithm.

Topological sort :: 
	A topological ordering is an ordering of the nodes in a directed graph where for each directed edge from node A to node B, node A appears before node B in the ordering.
	It is only define for DAG.
	Topological orderings are NOT unique. There can be multiple valid possible orderings.
	
	Many real world applications :: 
			Program build dependencies
			College class prerequisites
			Event scheduling
			etc
	
Kahn's algorithm :: 
	Kahn's algorithm is a simple topological sort algorithm can find a topological
	ordering in O(V+E) time.
	
	NOTE :: undirected trees are not DAG. 
			Though topological sort could be BFS but it is sometimes undefined.
	
	NOTE :: if a directed graph has cycle then every node in cycle depends on its parent and it is circular. Hence no topological sort.
	
	Approach :: 
		Form an array for all nodes and write their indegree in it.
		Start with the nodes having indegree = 0. And place them in queue in any order.
		Start working with the queue.
		Everytime you pop element from queue, write it in topological sort answer array. 
		You can only pop node if its indegree == 0.
		Everytime you pop a node, decrement the indegree of its adjacent nodes and if their indegree == 0 then push it in queue.
		
		Do until queue is empty.
		If you filled all the nodes in answer array, then that is a valid topological sequence, else there was a cycle in graph.
		{This technique works on all graph whether connected or not}.
	
	Time :: O(V + E) because we iterate over all edge and nodes once.
**/

vector<vector<int>> graph;
vector<int> indegree;
vector<int> topological_sequence;

int main(){
	
	int n,m;
	cin >> n >> m;
	
	graph.resize(n); // 0 based
	indegree.resize(n,0);
	topological_sequence.resize(n);
	
	// input m directed edges from n1 -> n2
	for(int i=0; i<m; i++) {
		int n1,n2;
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
		indegree[n2]++;
	}
	
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
		for(int adj:graph[node]) {
			indegree[adj]--;
			if(indegree[adj] == 0) {
				q.push(adj);
			}
		}
	}
	
	if(index == n) {
		cout << "topological sequence\n";
		for(int x:topological_sequence) {
			cout << x << " ";
		}
	} else {
		cout << "Graph has cycle hence no valid topological sequence";
	}
	
	
	
	
    return 0;
}
