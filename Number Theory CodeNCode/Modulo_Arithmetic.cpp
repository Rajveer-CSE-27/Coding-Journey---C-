#include <bits/stdc++.h>
using namespace std;
#define ll long long

// can prove anything by taking :: a = x*p + k1 and b = y*p + k2

int aModp(int a, int p) {
	
	// p = 0 : Invalid case
	
	if(a < 0 and p > 0) {
		int ans = ((a%p) + p)%p;
		return ans;
	}
	
	/** this will deal with all cases : 
		1. a>=0 and p<0
		2. a >=0 and p>0
		3. a<=0 and p<0
	**/
	return a%p;
}

int modMul(int a, int b, int p) {
	
	int ans = ((a%p) * (b%p))%p;
	return ans;
}

int modAdd(int a, int b, int p) {
	int ans = ((a%p) + (b%p))%p;
	return ans;
}

int modSub(int a, int b, int p) {
	int ans = ((a%p) - (b%p))%p;
	return ans;
}

int modPower(int a, int n, int p) {
	
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

int modInverseFermat(int a, int m) {
	
	// a * (modulo inverse of a) = 1 mod m
	
	// if gcd(a,m) != 1 then modulo inverse does not exist
	
	/** Fermat little theorem : 
						If m is prime number then a^(m-2) is the modulo inverse because
											a^(m-1) = 1modm hence a^(m-2) = a^(-1)modm
											
					Note : 1e9 + 7 is also prime
				Time :: log(m);
	**/
	
	return modPower(a,m-2,m);
	
}


int main() {
	
	
	return 0;
}
