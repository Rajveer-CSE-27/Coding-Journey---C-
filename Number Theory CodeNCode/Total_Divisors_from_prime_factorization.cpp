#include <bits/stdc++.h>
using namespace std;
#define ll long long

int modMul(int a, int b, int p) {
	
	int ans = ((a%p) * (b%p))%p;
	return ans;
}

int divisors(int n, vector<pair<int,int>> vc) {
	int ans = 1;
	for(int i=0; i<n; i++) {
		ans *= (vc[i].second + 1);
	}
	return ans;
}

int divisors(int n, vector<pair<int,int>> vc, int p) {
	int ans = 1;
	for(int i=0; i<n; i++) {
		ans = modMul(ans, vc[i].second + 1, p);
	}
	return ans;
}

int main() {
  //if we are given :: {2,2} , {3,1}, {5,3} then number is : 2*2*3*5*5*5 and we need to find total divisors of this number
  /**
    if a number is :: p1^(x1) * p2^(x2) * p3^(x3) *........* pn^(xn)
    then total divisors :: (x1 + 1)*(x2 + 1)*(x3 + 1)*.......*(xn + 1)

    because each pi has xi + 1 chances
  **/
  
	int n;
	cin >> n;
	vector<pair<int,int>> vc(n);
	for(int i=0; i<n; i++) {
		cin >> vc[i].first >> vc[i].second;
	}
	int totalDivisors = divisors(n, vc);
	int totalDivisorsWithMod = divisors(n, vc, 100);
	cout << totalDivisors << '\n' << totalDivisorsWithMod;
	
	return 0;
}
