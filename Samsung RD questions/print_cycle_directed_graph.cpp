#include <bits/stdc++.h>
using namespace std;
#define ll long long


/**
https://cses.fi/problemset/task/1678
Print cycle in directed graph.

**/

vector<int> ans;

void dfs(int node, vector<int>& vis, stack<int>& st, vector<vector<int>>& graph) {
	
	
	for(int adj:graph[node]) {
		
		if(vis[adj] == 0) {
			vis[adj] = 1;
			st.push(adj);
			dfs(adj, vis, st, graph);
			
			st.pop();
			vis[adj] = 2;
			
		} else if(vis[adj] == 1) {
			
			if(ans.size() == 0) {
				
				stack<int> st2 = st;
				while(st2.top() != adj) {
					ans.push_back(st2.top());
					st2.pop();
				}
				ans.push_back(adj);
				reverse(ans.begin(), ans.end());
				ans.push_back(adj);
				
			}
			
		}
		
		
	}
	
}

int main() {   
	
	int n,m;
	cin >> n >> m;
	
	
	vector<vector<int>> graph(n+1);
	for(int i=0; i<m; i++) {
		int n1,n2;
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
	}
	
	vector<int> vis(n+1, 0);
	// vis[i] = 0 means node is not visited
	// vis[i] = 1 means visited and it is currently on stack of dfs call
	// vis[i] = 2 means visited and not on stack
	stack<int> st;
	
	for(int i=1; i<=n; i++) {
		if(vis[i] == 0) {
			st.push(i);
			vis[i] = 1;
			dfs(i, vis, st, graph);
			vis[i] = 2;
			st.pop();
		}
	}
	
	if(ans.size() == 0) {
		cout << "IMPOSSIBLE";
	} else {
		
		cout << ans.size() << '\n';
		
		for(auto it:ans) {
			cout << it << " ";
		}
	}
	
 	
    return 0;
}
