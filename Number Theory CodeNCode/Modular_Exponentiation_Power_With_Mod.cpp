#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(logn)
// Iterative Code : Same as binary exponentiation bass %p add ho jaega in all multiplication
int power(int a, int n, int p) {
	
		
	int res = 1;
	while(n > 0) {
		if(n&1) {
			res *= a;
			res %= p;
			n--;
		} else {
			// that is square kar do
			a *= a;
			a %= p;
			n/=2;
		}
	}
	return res;
}

int main() {
	
	int a,n,p;
	cin >> a >> n >> p;
	
	cout << power(a,n,p) << '\n';
	
	return 0;
}
