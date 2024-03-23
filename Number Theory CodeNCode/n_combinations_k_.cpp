#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1e9 + 7;
int factorial[1000001];

int modPower(int a, int n, int p) {
	
	int res = 1;
	while(n > 0) {
		if(n&1) {
			res *= a;
			res %= p;
			n--;
		} else {
			a *= a;
			a %= p;
			n/=2;
		}
	}
	return res;
}

int modInverseFermat(int a, int m) {
	
	return modPower(a,m-2,m);
	
}

int nCk(int n, int k) {
	if(k > n) {
		return 0;
	}
	
	
	// ans = ((n!)%mod)/((k!)%mod * ((n-k)!)%mod)
	int res = factorial[n]; // equivalent to (n!)%mod
	res = (res * modInverseFermat(factorial[k], mod))%mod; // i.e finding inverse of k! and then multiplying with res
	
	res = (res * modInverseFermat(factorial[n - k], mod))%mod;
	return res;
	
}


signed main() {
	
	factorial[0] = 1;
	factorial[1] = 1;
	
	for(int i=2; i<=1e6; i++) {
		factorial[i] = (factorial[i-1] * i)%mod;
	}
	
	int n,k;
	cin >> n >> k;
	cout << nCk(n,k);
	return 0;
}
