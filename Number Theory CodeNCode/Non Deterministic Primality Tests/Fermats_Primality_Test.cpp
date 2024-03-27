#include <bits/stdc++.h>
using namespace std;
#define lli long long int

/**

Fermats Primality Test :
	-> Based on fermat's theorem :: for a prime p : a^(p-1) = 1 (mod p)
	-> the above equation does not hold for composite numbers in general
	-> hence choose a in range [2,p-2] and calculate : a^(p-1).
	-> If it is != 1modp then p is not prime and a is its fermat's witness for compositeness of p.
	-> If it is == 1modp the p is a probable prime.
	-> We will choose 'a' randomly.
	
	Q. Why range is between [2, p-2] and not between [2,p-1] i.e why (p-1) is not included?
			Proof(Not necessary) :
					1. We know that a^n % p = (a % p)^n from modular arithmetic
					2. We also know that p-1 % p = p-1
					3. When a = p-1, Fermat's little theorem (FLT) a^(p-1) becomes (p-1)^(p-1) % p
					4. Let S = (p-1)^(p-1) 
					5. S is simply a binomial expansion of p-1, and in the binomial expansion, every term contains p except for the last term. 
					6. Since all prime numbers p are odd, p-1 must be even. And if p-1 is even, then the last term of the binomial expansion must be 1
					7. That is; S = ap^{p-1} - bp^{p-2} + cp^{p-3} - ... + 1
					8. By modular arithmetic, we know that (a+b) % p = (a % p + b % p) % p. So S % p must give us 1, since all other terms contains p
					9. Therefore, it must be true that, for all odd values of p, (p-1)^(p-1) % p  will always give us 1, regardless of whether p is prime
					10. Therefore, a=p-1 is not useful as a primality test
	
	-> We perform multiple iterations and generate 'a' randomly so chances of verifying whether prime or not is more accurate.
	
	NOTE :: 
		->If P is composite and for some a fermat's little theorem holds then a is known as fermat liar and P in this case is known as Fermat PseudoPrime
		->Carmichael Numbers :
				There are some numbers (example 561 = 3 * 11 * 17) which are composite but for each a
				Such that GCD(a, P) = 1, fermat little theorem.
				These are usually very very rare.
				
	
**/


// multiplication method using binary exponentiation and also such that LL does not have overflow.
lli modMul(lli a, lli b, lli mod) {
	lli x = 0, y = a%mod;
	
	while(b > 0) {
		if(b%2 == 1) {
			x = (x + y)%mod;
		}
		y = (y*2LL)%mod;
		b /= 2;
	}
	
	return x%mod;
}

lli power(lli a, lli n, lli mod) {
	lli res = 1;
	
	while(n > 0) {
		if(n&1) {
			res = modMul(res, a, mod);
			n--;
		} else {
			a = modMul(a,a,mod);
			n /= 2;
		}
	}
	return res;
}

bool isPrime(lli n, int iterations = 5) {
	
	if(n <= 4) { // edge case
		if(n==2 or n==3) {
			return true;
		}
		return false;
	}
	
	for(int i=1; i<=iterations; i++) {
		lli a = 2 + rand() % (n-3); // generating a random number between 2 and p-2
		lli res = power(a, n-1, n);
		
		if(res != 1) { // i.e it is composite
			return false;
		}
	}
	
	return true;
	
}

int main() {
	
	lli t;
	cin >> t;
	while(t--) {
		lli n;
		cin >> n;
		if(isPrime(n) == true) {
			cout << "YES";
		} else {
			cout << "NO";
		}
	}
	
	return 0;
}
