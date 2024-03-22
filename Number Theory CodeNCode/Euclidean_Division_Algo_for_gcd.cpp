#include <bits/stdc++.h>
using namespace std;
#define ll long long

int gcd(int a, int b) {
	if(b == 0) {
		return a;
	}
	return gcd(b, a%b);
}

int main() {

  /**
  Observations from above algorithm ::
    1. gcd(x,0) = gcd(0,x) = x
    2. gcd(a,b) = gcd(b,a) :: can take example and see
    3. gcd(a,b) = gcd(a-b, b) = gcd(a, b-a)  ::: take a = g*X, b = g*Y where g is gcd of (a,b) and see results will always be = g
  **/
	
	return 0;
}
