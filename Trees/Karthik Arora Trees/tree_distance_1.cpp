// || जय जय जय बजरंग बली ||

#include <bits/stdc++.h>
using namespace std;
#define ll long long


/**
https://www.youtube.com/watch?v=N7e4CTfimkU&list=PLb3g_Z8nEv1j_BC-fmZWHFe6jmU_zv-8s&index=4
https://cses.fi/problemset/task/1132/

Time :: O(n) for finding depth + O(n) for fun function
Space :: O(n)
**/

vector<int> tree[200001];
int depth[200001];
int ans[200001];

int depth_fun(int node, int parent) {
	
	int d = 0;
	for(int i=0; i<tree[node].size(); i++) {
		if(tree[node][i] != parent) {
			d = max(d, depth_fun(tree[node][i], node));
		}
	}
	
	depth[node] = d;
	return 1 + d; 
}

void fun(int node, int parent, int best_parent_ans_except_node) {

	vector<int> prefixMax, suffixMax;
	
	for(int i=0; i<tree[node].size(); i++) {
		if(tree[node][i] != parent) {
			prefixMax.push_back(depth[tree[node][i]]);
			suffixMax.push_back(depth[tree[node][i]]);
		}
	}
	for(int i=1; i<prefixMax.size(); i++) {
		prefixMax[i] = max(prefixMax[i], prefixMax[i-1]);
	}
	for(int i=suffixMax.size()-2; i>=0; i--) {
		suffixMax[i] = max(suffixMax[i], suffixMax[i+1]);
	}
	
	int j = 0;
	for(int i=0; i<tree[node].size(); i++) {
		
		if(tree[node][i] != parent) {
			int best_left_child_depth = ((j == 0) ? INT_MIN : prefixMax[j-1]);
			int best_right_child_depth = ((j == suffixMax.size()-1) ? INT_MIN : suffixMax[j+1]);
			
			int temp = 1 + max({best_left_child_depth, best_right_child_depth, best_parent_ans_except_node});
			fun(tree[node][i], node, temp);
			
			j++;
		}
	}
	
	ans[node] = best_parent_ans_except_node;
	if(prefixMax.size() > 0) {
		ans[node] = max(ans[node], prefixMax[prefixMax.size()-1]);
	}
}

int main() {
	
	int n;
	cin >> n;
	
	for(int i=0; i<n-1; i++) {
		int n1,n2;
		cin >> n1 >> n2;
		tree[n1].push_back(n2);
		tree[n2].push_back(n1);
	}
	
	depth_fun(1,0);
	fun(1,0,-1);
	
	for(int i=1; i<=n; i++) {
		cout << 1 + ans[i] << " ";
	}
	
	return 0;
}
