#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Problem link :: https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/B

Approach :: 
	Looks like Min(Max()) type binary search question.
	Let us say we have a value x that represents maximum sum possible among all the k segments.
	Now we will find that this x is valid ?
		That is given x check that there exist k segments such that max. sum is <= k.
		
	We need to find minimum value of x that satisfies this property.
	
	The variable x has a bad-good sequence :: 0000000000111111111111...
	Hence we apply binary search on it.
	
		
**/

int n,k;
vector<int> vc;

bool is_good(ll x) {
	// if we can divide vc into exactly k segments such that max sum of each segment is <= x then x is good
	
	int i=0;
	ll limit = n - k;
	ll mxSm = 0;
	
	while(i < n) {
		if(limit == n) {
			return false;
		}
		int j = i;
		ll sm = 0;
		while(j < n and j <= limit) {
			if(sm + vc[j] > x) {
				if(sm == 0) {
					return false;
				}
				break;
			} else {
				sm += vc[j];
			}
			j++;
		}
		mxSm = max(mxSm, sm);
		limit++;
		i = j;
	}
	
	if(mxSm > x) {
		return false;
	}
	return true;
}

int main() {
	
	cin >> n >> k;
	vc.resize(n);
	for(int i=0; i<n; i++) {
		cin >> vc[i];
	}
	
	ll low = 0; // this is a sure bad value as no segement can have max. sum <= 0 as all values in vc are >= 1. and also k >= 1
	ll high = n*(1e9); // this is a sure good value as in worst case of k=1 and all values in vc = 1e9 then max. segment sum = n*(1e9)
	
	while(low + 1 < high) {
		ll mid = (low + high)/2;
		
		if(is_good(mid) == true) {
			high = mid;
		} else {
			low = mid;
		}
	}
	cout << high;
	
	return 0;
}
