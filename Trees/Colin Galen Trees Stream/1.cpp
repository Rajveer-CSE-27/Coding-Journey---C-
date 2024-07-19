// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**
https://codeforces.com/gym/304970/problem/A

Approach :: 
	For each node except root node, check wheter all its children are not respecting and node itself is not respecting.
	Because tree property :: Exactly 1 parent.

**/

void solve() {
	int n;
	cin >> n;
	
	vector<vector<int>> tree(n+1);
	vector<bool> respect(n+1); 
	vector<int> ans;
	
	int root;
	for(int i=1; i<=n; i++) {
		int parent, resp;
		cin >> parent >> resp;
		
		if(parent == -1) {
			root = i;
		} else {
			tree[parent].push_back(i);
		}
		
		if(resp == 1) {
			respect[i] = true;
		} else {
			respect[i] = false;
		}
	}
	
	for(int i=1; i<=n; i++) {
		if(i != root) {
			bool canDelete = true;
			for(int j=0; j<tree[i].size(); j++) {
				canDelete &= respect[tree[i][j]];
			}
			if(respect[i] == true and canDelete == true) {
				ans.push_back(i);
			} 
		}
	}
	
	sort(ans.begin(), ans.end());
	if(ans.size() == 0) {
		cout << -1;
		return;
	}
	for(auto it:ans) {
		cout << it << " ";
	}
}


int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    
    int tc = 1;
    //cin >> tc;
    while(tc--) {
        solve();
       	//cout << '\n';
        
    }
    return 0;
}
