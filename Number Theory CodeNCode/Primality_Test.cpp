#include <bits/stdc++.h>
using namespace std;


// O(n) time complexity
bool approach1(int n) {
	if(n <= 1) {
		return false;
	}
	
	for(int i=2; i<n; i++) {
		if(n%i == 0) {
			return false;
		}
	}
	return true;
	
}


// O(sqrt(n)) time complexity
bool approach2(int n) {
	if(n <= 1) {
		return false;
	}
	
	for(int i=2; i*i <=n; i++) {
		if(n%i == 0) {
			return false;
		}
	}
	return true;
	
	
	/** Proof :: Divisors exist in pairs.
				If a and b both are divisor pair for n then a*b = n and one lies before sqrt(n) and other after sqrt(n)
				Prove by 3 cases ::
					1. both a and b below sqrt(n) - False
					2. both a and b above sqrt(n) - False
					3. one below and another above - Always true
	**/

}



int main() {
	
	int n;
	cin >> n;
	
	(approach1(n)) ? cout << "Prime\n" : cout << "NotPrime\n";
	(approach2(n)) ? cout << "Prime\n" : cout << "NotPrime\n";
	
	return 0;
}
