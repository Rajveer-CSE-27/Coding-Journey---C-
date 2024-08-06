// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=sD1IoalFomA&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=13

LCA in trees using Euler tour.
It will answer all LCA queries in O(1) and there will be a preprocessing of O(nlogn)

MUST SEE THE VIDEO FOR GOOD UNDERSTANDING.

Approach :: 
	
	The Eulerian tour method begins by finding an Eulerian tour of the edges in a rooted tree starting from root node.
	Rather than doing the Euler tour on the white edges of our tree, we're going to do the Euler tour on a new set of imaginary green edges (see 4:57) which wrap around the tree. 
	This ensures that our tour visits every node in the tree.
	
	Start an Eulerian tour (Eulerian circuit) at the root node, traverse all green edges, and finally return to the root node.
	As you do this,keep track of which nodes you visit and this will be your Euler tour.
	
	Construct 2 arrays.
		Depth array will store the value of depth of current node of euler tour.
		Node array will store node pointer/value of current node of euler tour.
	
	If there are n nodes in tree then euler tour will have 2*n - 1 node visits and hence size of Depth, Node array = 2*n - 1.
	
	For each node n we will keep track that when it occured for last time the the Node array.
	
	Let we want to find lca(u,v).
	We will get 2 indices :: i1 = index of last occurence of u in Node array
							 i2 = index of last occurence of v in Node array
	
	So in the depth array we will find minimum value between [i1,i2]. Let it be at i3.
	Hence (Node[i3] = answer).
	
	Because it will be the node with the highest depth and parent of both u,v.
	
	Now minimum in range [i1,i2] could be found with sparse table for RMQ.
	
**/

const int N = 200001;
int floor_log2[N];
int sparseTable[N][25];

vector<vector<int>> tree;
vector<int> node;
vector<int> depth;
vector<int> lastOccurence;


void euler_tour(int root, int parent, int curr_depth) {
	
	node.push_back(root);
	depth.push_back(curr_depth);
	
	//dfs
	for(int child:tree[root]) {
		if(child != parent) {
			euler_tour(child, root, curr_depth+1);
			// after coming back from every child
			node.push_back(root);
			depth.push_back(curr_depth);
		}
	}
	
}

void compute_log() {
	
	floor_log2[1] = 0;
	for(int i=2; i<N; i++) {
		floor_log2[i] = 1 + floor_log2[i/2];
	}
}

void build_sparseTable() {
	int n = depth.size();
	
	for(int l=n-1; l>=0; l--) {
		for(int w=0; w<25; w++) {
			int r = l + (1<<w) - 1;
			if(r >= n) {
				break;
			}
			
			if(w == 0) {
				sparseTable[l][w] = depth[l];
			} else {
				sparseTable[l][w] = min(sparseTable[l][w-1], sparseTable[l + (1<<(w-1))][w-1]);
			}
			
		}
	}
	
}

int query(int l, int r) {
	
	// need to find minimum depth between i1, i2.
	int w = r - l + 1;
	int power = floor_log2[w];
	
	int mnDepth = min(sparseTable[l][power], sparseTable[r - (1<<power) + 1][power]);
	return mnDepth;
} 



int main(){
	
	int n;
	cin >> n;
	tree.resize(n); // this if for 0 indexed tree
	
	for(int i=0; i<n-1; i++) {
		int n1,n2;
		cin >> n1 >> n2;
		tree[n1].push_back(n2);
		tree[n2].push_back(n1);
	}
	
	// assume root as 0.
	
	euler_tour(0,-1, 0);
	
	lastOccurence.resize(n, -1);
	for(int i=node.size()-1; i>=0; i--) {
		if(lastOccurence[node[i]] == -1) {
			lastOccurence[node[i]] = i;
		}
	}
	
	// build sparse table over depth vector.
	compute_log();
	build_sparseTable();
	
	vector<map<int,int>> latest_depth(depth.size());
	map<int,int> mp;
	
	for(int i=0; i<depth.size(); i++) {
		mp[depth[i]] = i;
		latest_depth[i] = mp; 
	}
	
	int q;
	cin >> q;
	while(q--) {
		int n1,n2;
		cin >> n1 >> n2;
		
		int l = lastOccurence[n1];
		int r = lastOccurence[n2];
		if(l > r) {
			swap(l,r);
		}
		
		int mnDepth = query(l,r);
		
		// find which element in this range has this depth (this will always be unique)
		map<int,int> temp = latest_depth[r];
		int index = temp[mnDepth];
		
		
		cout << node[index] << '\n';
	}
	
    return 0;
}
