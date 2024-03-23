#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**

Explaination :: 
	Euler Toitent function counts number of positive integers upto n which are coprime with n. i.e gcd(a,b) = 1
	 
	Ex. phi(5) = 4 : 1,2,3,4 because :: gcd(1,5) = gcd(2,5) = gcd(3,5) = gcd(4,5) = 1
	Ex. phi(12) = 4 : 1,5,7,11  because :: gcd(1,12) = gcd(5,12) = gcd(7,12) = gcd(11,12) = 1
	

	Observation : 
			1. phi(p) = p-1 if p is a prime number.
			2. phi(p^x) = (p^(x-1)) * (p-1) if p is a prime number.
						Proof :: phi(p^x) = p^x - number of integers not coprime with p // because number is p^x hence any number not coprime with it will be a multiple of p.
										  = p^x - number of multiples of p
										  = p^x - (p^x)/p
										  = (p^(x-1)) * (p-1)
										  
	Deriving formula for ETF :
		Let we write a number n in prime factorization form :: 
			N = p1^x1 * p2^x2 * p3^x3 * ..... * pk^xk
			phi(n) = phi(p1^x1) * phi(p2^x2) * phi(p3^x3) * ..... * phi(pk^xk) // because any two prime numbers are coprime
			phi(n) = ((p1^(x1-1))*(p1-1)) * ((p2^(x2-1))*(p2-1)) * ((p3^(x3-1))*(p3-1)) * ...... * ((pk^(xk-1))*(pk-1))
			phi(n) = N * ((p1 - 1)/p1) * ((p2 - 1)/p2) * ((p3 - 1)/p3) *......* ((pk - 1)/pk)
			
		Ex. phi(6) = 6 * ((2-1)/2) * ((3-1)/3) = (6 * 1 * 2)/(2 * 3) = 2
		Hence time complexity of this approach is sqrt(n). Because that is the time we need to get all prime factors of n
		See appraoch 2
		
	
**/


// Time complexity :: O(n * logn)
int approach1(int n) {
	int cnt = 0;
	for(int i=1; i<n; i++) {
		if(__gcd(i,n) == 1) {
			cnt++;
		}
	}
	
	return cnt;
}

// Time complexity :: O(sqrt(n)) // best 
int approach2(int n) {
	int res = n;
	
	for(int i=2; i*i <= n; i++) {
		if(n%i == 0) {
			res *= (i-1);
			res /= i;
			
			while(n%i == 0) {
				n /= i;
			}
		}
	}
	
	//edge case
	if(n > 1) {
		res *= (n-1);
		res /= n;
	}
	return res;
}

//Time Complexity :: O(n*loglogn) , Space : O(n) ; used when n <= 1e6
void approach3(int n) {
	
	// This uses sieve.
	// Use this approach if you need to answer multiple queries between 1 to n and n <= 1e6
	
	int mxN = 1000001;
	int phi[1000001];
	for(int i=1; i<mxN; i++) {
		phi[i] = i;
	}
	
	for(int i=2; i<mxN; i++) {
		if(phi[i] == i) { // this means i is a prime number
			
			for(int j=i; j<mxN; j+=i) { // note this starts from i and not from i*i
				phi[j] *= (i-1);
				phi[j] /= i;
			}
		}
	}
	
	for(int i=1; i<=n; i++) {
		cout << phi[i] << " ";
	}
	
}


int main() {
	
	cout << approach1(31) << " " << approach2(31) << '\n' ;
	
	approach3(32);
	return 0;
}
