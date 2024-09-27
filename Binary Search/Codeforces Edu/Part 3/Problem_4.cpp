
// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,d;
vector<vector<pair<int,int>>> graph;

bool preCheck() {
	
	queue<int> q;
	q.push(1);
	
	int edgeCnt = 0;
	
	vector<bool> vis(n+1, false);
	vis[1] = true;
	
	while(!q.empty()) {
		
		edgeCnt++;
		int s = q.size();
		while(s--) {
			
			int node = q.front();
			q.pop();
			
			for(pair<int,int> adj:graph[node]) {
				int next = adj.first;
				if(vis[next] == false) {
					q.push(next);
					vis[next] = true;
					if(next == n) {
						return (edgeCnt <= d);
					}
				}
			}
		}
	}
	
	return false;
}

bool check(int x) {
	
	// minium number of edges to reach from 1 to n such that no edge length has value > x
	
	queue<int> q;
	q.push(1);
	
	int edgeCnt = 0;
	
	vector<bool> vis(n+1, false);
	vis[1] = true;
	
	
	while(!q.empty()) {
		
		edgeCnt++;
		int s = q.size();
		while(s--) {
			int node = q.front();
			q.pop();
			
			for(pair<int,int> adj:graph[node]) {
				int next = adj.first;
				int w = adj.second;
				
				if(vis[next] == false and w <= x) {
					vis[next] = true;
					q.push(next);
					
					if(next == n) {
						return (edgeCnt <= d);
					}
				}
			}
		}
	}
	
	return false;
}


signed main() {

	cin >> n >> m >> d;
	
	graph.resize(n+1);
	
	for(int i=0; i<m; i++) {
		int n1,n2,w;
		cin >> n1 >> n2 >> w;
		graph[n1].push_back({n2,w});
	}
	
	// checking whether path exists
	if(preCheck() == false) {
		cout << -1;
		return 0;
	}
	
	int low = -1; // obvious bad value
	int high = 1e9; // obious good value
	
	int ans = high;
	while(low <= high) {
		int mid = (low + high)/2;
		
		if(check(mid) == true) {
			ans = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	
	
	queue<int> q;
	vector<int> parent(n+1, -1);
	
	q.push(1);
	
	bool flag = true;
	
	while(!q.empty() and flag == true) {
		int s = q.size();
		while(s > 0 and flag == true) {
			int node = q.front();
			q.pop();
			
			for(pair<int,int> adj:graph[node]) {
				int next = adj.first;
				int w = adj.second;
				
				if(parent[next] == -1 and w <= ans) {
					parent[next] = node;
					q.push(next);
					
					if(next == n) {
						flag = false;
						break;
					}
				}
			}
			s--;
		}
	}
	
	vector<int> path;
	path.push_back(n);
	int next = parent[n];
	
	while(next != -1) {
		path.push_back(next);
		next = parent[next];
	}
	
	reverse(path.begin(), path.end());
	
	cout << path.size() - 1 << '\n';
	for(auto it:path) {
		cout << it << " ";
	}
	
	return 0;
}
