// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;

/**
https://www.youtube.com/watch?v=qNObsKl0GGY&list=PLb3g_Z8nEv1j_BC-fmZWHFe6jmU_zv-8s&index=3
https://cses.fi/problemset/task/1131

Approach :: 
	For each node find whether it can be an intermediary node in the longest path.
	That is for each node find its 2 deepest child subtrees. Add their height and update the ultimate answer.

Time :: O(n)
Space :: O(n) stack space.

**/


vector<vector<int>> tree;
int ans = 0;

int fun(int node, int parent) {
	
	int mx = 0, smx = 0;
	
	for(int i=0; i<tree[node].size(); i++) {
		if(tree[node][i] != parent) {
			int temp = fun(tree[node][i], node);
			
			if(temp >= mx) {
				smx = mx;
				mx = temp;
			} else if(temp > smx) {
				smx = temp;
			}
		}
	}
	
	int tempAns = mx + smx; // this will find the edges between 2 farthest nodes of current subtree with root as node and path paas through node.
	ans = max(ans, tempAns);
	
	return 1+mx; // this returns height of the subtree with node as root.
	
}

void solve() {
	int n;
	cin >> n;
	
	tree.resize(n+1);
	for(int i=0; i<n-1; i++) {
		int n1,n2;
		cin >> n1 >> n2;
		tree[n1].push_back(n2);
		tree[n2].push_back(n1);
	}
	int height = fun(1,0);
	cout << ans;
}

int main() {
    
   	int tc = 1;
   	//cin >> tc;
   	while(tc--) {
   		solve();
   		//cout << '\n';
   	}
    
    return 0;
}
