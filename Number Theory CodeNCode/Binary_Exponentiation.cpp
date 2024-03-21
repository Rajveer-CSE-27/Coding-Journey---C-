#include <bits/stdc++.h>
using namespace std;


// Time Complexity : O(n)
int approach1(int a, int n) {
	if(n == 0) {
		return 1;
	}
	
	int res = a;
	for(int i=0; i<n-1; i++) {
		res *= a;
	}
	return res;
}

// Time Comlexity : O(logn)

int approach2(int a, int n) {
	if(n==0) {
		return 1;
	}
	
	if(n&1) {
		int temp = approach2(a, (n-1)/2);
		return a*temp*temp;
	}
	int temp = approach2(a,n/2);
	return temp*temp;
}

// Time Complexity : O(logn)
// Iterative Code
int approach3(int a, int n) {
	
	
	// if  n = 10 the :: 1010 = a^8 * a^2
	
	int res = 1;
	while(n > 0) {
		if(n&1) {
			res *= a;
			n--;
		} else {
			// that is square kar do
			a *= a;
			n/=2;
		}
	}
	return res;
}

int main() {
	
	int a,n;
	cin >> a >> n;
	
	cout << approach1(a,n) << '\n';
	cout << '\n';
	cout << approach2(a,n) << '\n';
	cout << '\n';
	cout << approach3(a,n) << '\n';
	
	return 0;
}
