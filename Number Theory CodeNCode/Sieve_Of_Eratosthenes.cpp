#include <bits/stdc++.h>
using namespace std;


// Time Comlexity : O(n*loglogn) + O(n) = O(n*loglogn)
// Space Complexity : O(n)
void sieve(int n) {
	
	vector<bool> vc(n+1, true);
	
	for(int i=2; i*i <= n; i++) {
		if(vc[i] == true) {
			for(int j=i*i; j<=n; j+=i) {
				vc[j] = false;
			}
		}
	}
	for(int i=2; i<=n; i++) {
		if(vc[i] == true) {
			cout << i << " ";
		}
	}
}

int main() {
	
	int n;
	cin >> n;
	
	sieve(n);
	
	return 0;
}
