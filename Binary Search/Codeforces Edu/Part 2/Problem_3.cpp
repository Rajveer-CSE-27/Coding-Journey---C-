
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Problem Link :: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C

Approach ::

	Here we observe that for time variable x there is a bad-good sequence .
		0000000000011111111111...... and we need to find min good (x).
	Hence will apply binary search.
	
**/

ll n,x,y;

bool is_good(int t) {	
	int n1 = t/x;
	int n2 = t/y;
	
	return ((n1 + n2) >= (n));
} 


int main() {
	
	cin >> n >> x >> y;
	n--;
	
	ll low = 0; // this is definitely bad because in 0 time we cannot print n copies.
	ll high = n*(min(x,y)); // this is sure a good value.
	
	while(low + 1 < high) {
		ll mid = (low + high)/2;
		if(is_good(mid) == true) {
			high = mid;
		} else {
			low = mid;
		}
	}
	cout << high + min(x,y); 
	
	return 0;
}
