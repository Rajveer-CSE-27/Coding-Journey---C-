
#include <bits/stdc++.h>
using namespace std;
#define int long long

/**
https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/G
**/
int k,n, sm = 0;
vector<int> vc;

bool is_good(int x) {
	int req = x*k;
	
	if(req > sm) {
		return false;
	}
	
	int start = 0;
	int cnt = 0;
	for(int i=0; i<n; i++) {
		int val = min(vc[i], x);
		if(start + val >= x) {
			cnt++;
		}
		start = (start + val)%x;
	}
	if(cnt >= k) {
		return true;
	}
	return false;
}

signed main() {
	
	cin >> k >> n;
	vc.resize(n);
	for(int i=0; i<n; i++) {
		cin >> vc[i];
		sm += vc[i];
		
	}
	
	int low = 0; // we can always form council with 0 students. Hence first good value;
	int high = n*(1e9); // from constraints that is if k=1 and all a[i] = 1e9
	
	while(low + 1 < high) {
		int mid = (low + high)/2;
		if(is_good(mid) == true) {
			low = mid;
		} else {
			high = mid;
		}
	}
	
	cout << low;
	
	return 0;
}
