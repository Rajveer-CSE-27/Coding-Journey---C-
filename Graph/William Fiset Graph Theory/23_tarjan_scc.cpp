// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long


/**
https://www.youtube.com/watch?v=wUgWX0nc4NY&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=23
https://www.geeksforgeeks.org/problems/strongly-connected-component-tarjanss-algo-1587115621/1

Tarjan's Strongly Connected Component (SCC) Algorithm ::
	
	-> Strongly Connected Components (SCCs) can be thought of as self-contained cycles within a directed graph where every vertex in a given cycle
	   can reach every other vertex in the same cycle.
	 
	-> Done using DFS hence time complexity :: O(V + E)
	
	-> Approach :: 
			1. Mark the id of each node as unvisited.
			2. Start DFS. Upon visiting a node assign it an id and a low-link value. Also mark current nodes as visited and add them to a seen stack/map.
			3. On DFS callback, if the previous node is on the stack then min the current node's low-link value with the last node's low-link value (This allows low-link values to propagate throughout cycles.).
			4. After visiting all neighbors, if the current node started a connected component (it's id equals it's low link value) then pop nodes off stack until current node is reached.
			

**/

vector<vector<int>> graph;
vector<int> ids; 
vector<int> low_link; 
vector<bool> onStack;
stack<int> st;

int currId = 0, sccCnt = 0;

void dfs(int node) {
	
	st.push(node); // push node inside stack
	onStack[node] = true; // this node is part of stack
	ids[node] = currId; // id of node is updated
	low_link[node] = currId; // initially low_link == currId
	currId++;
	
	for(int adj:graph[node]) {
		if(ids[adj] == -1) { // if neighbour is not visited then visit it
			dfs(adj);
		}
		
		// upon returning
		if(onStack[adj] == true) { // if the neighbour is still on stack then it could be a part of scc containing the current node
			low_link[node] = min(low_link[node], low_link[adj]); // update the low link of node with low link of neighbour if possible so the low link can propagate through scc
		}
		
	}
	
	//checking if current node can be a start of a scc hence all nodes in this scc will have same low link.
	if(ids[node] == low_link[node]) {
		while(st.size() > 0) {
			int tempNode = st.top();
			st.pop();
			
			onStack[tempNode] = false;
			low_link[tempNode] = ids[node];
			if(tempNode == node) { // stop when you pop out the node which starts this scc
				break; 
			}
		}
		sccCnt++;
	}
	
	
}


int main(){
	
	int n,m;
	cin >> n >> m;
	
	graph.resize(n); // 0 based
	ids.resize(n,-1);
	low_link.resize(n,0);
	onStack.resize(n,false);
	
	
	for(int i=0; i<m; i++) {
		int n1,n2;
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
	}
	
	for(int i=0; i<n; i++) {
		if(ids[i] == -1) { // node i is unvisited hence do dfs from this
			dfs(i);
		}
	}
	
	
	// printing the strongly connected components.
	
	map<int,vector<int>> sccComponents;
	for(int i=0; i<n; i++) {
		sccComponents[low_link[i]].push_back(i);
	}
	
	cout << sccCnt << '\n';
	for(auto it:sccComponents) {
		vector<int> temp = it.second;
		for(int x:temp) {
			cout << x << " ";
		}
		cout << '\n';
	}
	
    return 0;
}
