#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

int dfs(int node, int par, vector<vector<int>>& tree, vector<int>& node_val, vector<int>& mxSumThroughNode) {
	// will give max sum path from current node
	
	vector<int> child;
	for(int adj:tree[node]) {
		if(adj != par) {
			
			child.push_back(dfs(adj, node, tree, node_val, mxSumThroughNode));
			
		}
		
	}
	
	int mx, smx;
	bool flag1 = false, flag2 = false;
	
	for(int x:child) {
		
		if(flag1 == false) {
			mx = x;
			flag1 = true;
			
		} else if(flag2 == false) {
			if(x > mx) {
				smx = mx;
				mx = x;
			} else {
				smx = x;
			}
			flag2 = true;
			
		} else {
			if(x > mx) {
				smx = mx;
				mx = x;
			} else if(x > smx) {
				smx = x;
			}
		}
		
	}
	
	int res = node_val[node];
	if(flag1 == true) {
		res += mx;
	}
	
	if(flag2 == true) {
		res += smx;
	}
	mxSumThroughNode[node] = res;
	
	res = node_val[node];
	if(flag1 == true) {
		res += mx;
	}
	
	if(res < 0) {
		res = 0;
	}
	
	return res;
	
}


int main() {
  
  int n;
  cin >> n;
  
  vector<int> node_val(n);
  for(int i=0; i<n; i++) {
  	cin >> node_val[i];
  }
  
  vector<vector<int>> tree(n);
  for(int i=0; i<n-1; i++) {
  	int n1, n2;
  	cin >> n1 >> n2;
  	
  	tree[n1].push_back(n2);
  	tree[n2].push_back(n1);
  }
  
  // rooting at node 0
  vector<int> mxSumThroughNode(n);
  
  int c = dfs(0, -1, tree, node_val, mxSumThroughNode);
  
  int ans = INT_MIN;
  for(int i=0; i<n; i++) {
  	ans = max(ans, mxSumThroughNode[i]);
  }
  cout << ans;
  
  return 0;
  
}
