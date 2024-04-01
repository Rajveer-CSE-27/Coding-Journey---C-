
#include <bits/stdc++.h>
using namespace std;
#define ld long double

/**
Problem Link :: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/E

Binary search on real numbers.

**/

int main() {
	
	ld c;
	cin >> c;
	ld low = 0, high = 1e5; // because high = 1e5 will give c > 10^10 hence this can be a valid high
	
	for(int i=0; i<80; i++) { // can also take 100
		ld mid = (low + high)/2;
		ld value = mid*mid + sqrt(mid);
		if(value > c) {
			high = mid;
		} else {
			low = mid;
		}
	}
	
	cout << fixed <<  setprecision(15) << high;
	
	return 0;
}
