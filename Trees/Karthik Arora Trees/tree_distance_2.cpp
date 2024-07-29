// || जय जय जय बजरंग बली ||

#include <bits/stdc++.h>
using namespace std;
#define int long long

/**
https://www.youtube.com/watch?v=nGhE4Ekmzbc&list=PLb3g_Z8nEv1j_BC-fmZWHFe6jmU_zv-8s&index=5
https://cses.fi/problemset/task/1133/
**/

vector<int> tree[200001];
int subtree_child_sum[200001];
int subtree_nodes_cnt[200001];
int res[200001];
int n;

int subtree_size(int node, int parent) { // finds the number of nodes in the subtree
	
	int ans = 1;
	for(int i=0; i<tree[node].size(); i++) {
		if(tree[node][i] != parent) {
			ans += subtree_size(tree[node][i], node);
		}
	}
	
	subtree_nodes_cnt[node] = ans;
	return ans;
}

int subtree_children_sm(int node, int parent) {//find the distance of all children nodes from current
	
	int ans = 0;
	for(int i=0; i<tree[node].size(); i++) {
		if(tree[node][i] != parent) {
			ans += subtree_children_sm(tree[node][i], node) + subtree_nodes_cnt[tree[node][i]];
		}
	}
	
	subtree_child_sum[node] = ans;
	return ans;
}

void fun(int node, int parent, int parent_without_curr_node) {
	
	vector<int> prefixSm, suffixSm;
	for(int i=0; i<tree[node].size(); i++) {
		if(tree[node][i] != parent) {
			
			int val = (subtree_nodes_cnt[tree[node][i]] + subtree_child_sum[tree[node][i]]);
			prefixSm.push_back(val);
			suffixSm.push_back(val);
		}
	}
	for(int i=1; i<prefixSm.size(); i++) {
		prefixSm[i] += prefixSm[i-1];
	}
	for(int i=suffixSm.size()-2; i>=0; i--) {
		suffixSm[i] += suffixSm[i+1];
	}
	
	int j = 0;
	for(int i=0; i<tree[node].size(); i++) {
		
		if(tree[node][i] != parent) {
			int leftSm = (j == 0) ? 0 : prefixSm[j-1];
			int rightSm = (j == suffixSm.size()-1) ? 0 : suffixSm[j+1];
			
			int temp = parent_without_curr_node + leftSm + rightSm;
			

			if(parent != 0) { // adding number of nodes in non child tree
				int add = n - subtree_nodes_cnt[node];
				temp += add;
			}
			
			fun(tree[node][i], node, temp);
			
			j++;
		}
	}
	
	res[node] = subtree_child_sum[node] + (parent_without_curr_node + (n - subtree_nodes_cnt[node]));
	
}

signed main() {
	
	cin >> n;
	
	for(int i=0; i<n-1; i++) {
		int n1,n2;
		cin >> n1 >> n2;
		tree[n1].push_back(n2);
		tree[n2].push_back(n1);
	}
	
	subtree_size(1,0);
	subtree_children_sm(1,0);
	
	fun(1,0,0);
	for(int i=1; i<=n; i++) {
		cout << res[i] << " ";
	}
	
	
	return 0;
}
