// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define int long long

/**
https://cses.fi/problemset/task/1650/
**/

signed main(){
	int n,q;
	cin >> n >> q;
	
	vector<int> vc(n+1,0);
	for(int i=1; i<=n; i++) {
		cin >> vc[i];
	}
	for(int i=1; i<=n; i++) {
		vc[i] ^= vc[i-1];
	}
	
	while(q--) {
		int l,r;
		cin >> l >> r;
		
		int ans = vc[r] ^ vc[l-1];
		cout << ans << '\n';
	}
	
	
    return 0;
}
