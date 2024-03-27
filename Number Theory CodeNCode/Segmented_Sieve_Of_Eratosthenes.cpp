#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
WHEN TO USE ?
	When you need to find prime numbers in range L to R where L and R can be really large (like
	10^12 ) but still R - L + 1 <= 10^6.
	
	STEPS :: 
	
		Main logic : If none of the previous prime numbers are able to divide a number then that number is prime number
	
		1. Generate all prime numbers till sqrt(R).
		2. Create an array of size R - L + 1 and set all elements to 0. NOTE : {0 indicates prime, 1 : non-prime}
		3. For each prime p  in range [2, sqrt(R)] :
					For each multiple m of p in range [L,R] mark index m - L = 1 {i.e non prime}
					// the logic of subtracting L from m is same as setting L as first element in array
					
	
		At end :: if arr[x - L] = 0 then x is prime. else not for x = [L,R]
			

**/

vector<bool> sieve(int n) {
	
	vector<bool> vc(n+1, true);
	
	for(int i=2; i*i <= n; i++) {
		if(vc[i] == true) {
			for(int j=i*i; j<=n; j+=i) {
				vc[j] = false;
			}
		}
	}
	
	return vc;
}

void segmentedSieve(int l, int r) {
	vector<bool> sieveFinal(r - l + 1, true);
	
	int sq = floor(sqrt((double)r));
	vector<bool> primesTillSqrt_R;
	primesTillSqrt_R = sieve(sq);
	
	for(int i=2; i<primesTillSqrt_R.size(); i++) {
		if(primesTillSqrt_R[i] == true) {
			int prime = i;
			for(int j=0; j<r-l+1; j++) {
				if((l+j)%prime == 0) {
					sieveFinal[j] = false;
				}
			}
		}
	}
	
	for(int i=0; i<r-l+1; i++) {
		if(sieveFinal[i] == true) {
			cout << (i+l) << " ";
		}
	}
	
	
}

int main() {
	
	int L,R;
	cin >> L >> R;
	
	segmentedSieve(L,R);
	
	return 0;
}
