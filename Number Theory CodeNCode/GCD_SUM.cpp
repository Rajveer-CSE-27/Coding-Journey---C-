#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**

Explaination :: 
	we need to find : sum (i = 1 to N {gcd(i,N)})
	let you are give q queries
	
	Approach 1 : 
		for each query you have a number n
			for i=1 to n find gcd(i,n) and add it up
		Time : O(q * nlogn)
		
	Approach 2 :
		Observation 1 : GCD(i, N) = one of the divisors of N.
						Ex. N = 12 then GCD(1, 12) = 1
										GCD(2, 12) = 2
										GCD(3, 12) = 3
										GCD(4, 12) = 4
										GCD(5, 12) = 1
										GCD(6, 12) = 6
										GCD(7, 12) = 1
										GCD(8, 12) = 4
										GCD(9, 12) = 3
										GCD(10, 12) = 2
 										GCD(11, 12) = 1
										GCD(12, 12) = 12
		
		Observation 2 : Instead of running loop from 1 to N, we can check for each divisor d of N
						how many numbers i are there with GCD(i, N) = d and then sum of products.
						Ex. n = 12 : res = 1*4 + 2*2 +3*2 + 4*2 + 6*1 + 12*1

		
		How many integers are there from 1 to N having gcd d with N ?
		Note: d is divisor of N
				let x1, x2, ×3,...., xm are m different integers from 1 to N such that their GCD with N is d.
				*** since GCD(xi, N) = d then GCD(xi / d, N/ d) = 1
				1 <=xi <= N
				1 <= xi/d <= N/d
				hence = #of integers having GCD d with N = #of integers Coprime with N/d
				and #of integers Coprime with N/d = phi(N/d)
				
				And if we use sieve for phi(N/d) that is we calculate phi in preprocessing then time for getting phi(N/d) = O(1)
				
		Hence overall time complexity :: O(q * sqrt(n))		
	
**/


// Time complexity :: O(q * n * logn)
void approach1() {
	int q;
	cin >> q;
	vector<int> vc(q);
	for(int i=0; i<q; i++) {
		cin >> vc[i];
	}
	
	for(int i=0; i<q; i++) {
		int n = vc[i];
		int res = 0;
		for(int j=1; j<=n; j++) {
			res += __gcd(j,n);
		}
		cout << res << " ";
	}
}

// Time complexity :: O(q * sqrt(n)) // best 
void approach2() {
	
	int q;
	cin >> q;
	vector<int> vc(q);
	for(int i=0; i<q; i++) {
		cin >> vc[i];
	}
	
	int mxN = 1000001;
	int phi[1000001];
	for(int i=1; i<mxN; i++) {
		phi[i] = i;
	}
	
	for(int i=2; i<mxN; i++) {
		if(phi[i] == i) {
			for(int j=i; j<mxN; j+=i) {
				phi[j] *= (i-1);
				phi[j] /= i;
			}
		}
	}
	
	for(int i=0; i<q; i++) {
		int n = vc[i];
		
		int res = 0;
		for(int j=1; j*j <=n; j++) {
			if(n%j == 0) {
				int divisor1 = j;
				int divisor2 = n/j;
				res += divisor1 * (phi[n/divisor1]);
				
				if(divisor1 != divisor2) {
					res += divisor2 * (phi[n/divisor2]);
				}
				
			}
		}
		cout << res << " ";
	}
}


int main() {
	
	approach1();
	cout << '\n';
	approach2();
	return 0;
}
