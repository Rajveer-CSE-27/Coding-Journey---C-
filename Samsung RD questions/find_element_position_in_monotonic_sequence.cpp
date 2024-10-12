#include <bits/stdc++.h>
using namespace std;
#define int long long


/**
https://www.geeksforgeeks.org/find-element-position-in-given-monotonic-sequence/

Given an integer k and a monotonic increasing sequence: 
f(n) = an + bn [log2(n)] + cn^3 where (a = 1, 2, 3, …), (b = 1, 2, 3, …), (c = 0, 1, 2, 3, …) 
The task is to find the value n such that f(n) = k, if k doesn’t belong to the sequence then print 0. 

Note: Values are in such a way that they can be expressed in 64 bits and the three integers a, b and c do not exceed 100.


Binary search on answer lagega for n.

High will be decided based on constraint of c.
if c == 0 then high can go upto 1e18
if c != 0 then high can only go upto 1e6.


**/


int check(int a, int b, int c, int n) {
	int ans = a*n;
	ans += b * n * floor(log2(n));
	ans += c*n*n*n;
	
	return ans;
}

signed main() {   

	short a,b,c;
	int k;
	cin >> a >> b >> c;
	cin >> k;

	// checking whether 1 satisfies the equation	
	int val = a + c;
	if(k == val) {
		cout << 1;
		return 0;
	}
	
	
	int low = 1; // bad
	int high;
 	if(c == 0) {
 		high = 1e18;
 	} else {
 		high = 1e6;
 	}
 	
 	
 	while(low <= high) {
 		int mid = (low + high)/2;
 		val = check(a,b,c,mid);
 		
 		if(val == k) {
 			cout << mid;
 			return 0;
 		}
 		if(val > k) {
 			high = mid - 1;
 		} else {
 			low = mid + 1;
 		}
 	}
 	
    return 0;
}
