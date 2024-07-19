// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**

Trees :: 
	-> Form of graph
	-> n vertices
	-> n-1 edges
	-> acyclic
	-> connected
	-> unique path between any two nodes
	-> each node except the root node has exactly one parent.
	
	-> Agar question me :: 
			-> n-1 edges diya hai and acyclic diya hai to tree banega
			-> n-1 edges diya hai and connected diya hai to tree banega
			-> n-1 , acyclic, connected teeno diya hai to tree banega
			-> connected and unique path diya hai to tree banega
		
	-> Store a tree :: 
		with adjacency list.
		tree[i] = {j,k,l,...}
		where node i has edge with node j,k,l,....

	-> time complexity of BFS and DFS is O(v + e).
				v = number of vertices
				e = number of edges.
				
				Because every vertex and edge is visited once hence overall time complexity :: O(v + e).
	
	-> You can call a tree rooted at node (n) if we assume that we will start everything from that node. i.e the root node.

**/




void solve() {
	
}


int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    
    int tc = 1;
    cin >> tc;
    while(tc--) {
        solve();
       	cout << '\n';
        
    }
    return 0;
}
