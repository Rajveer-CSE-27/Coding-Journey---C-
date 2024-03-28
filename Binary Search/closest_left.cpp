#include <bits/stdc++.h>
using namespace std;

/**

Given an array of 𝑛 numbers, sorted in non-decreasing order, and 𝑘 queries. 
For each query, print the maximum index of an array element not greater than the given one.

Input
The first line of the input contains integers 𝑛 and 𝑘 (0<𝑛,𝑘≤105), the length of the array and the number of queries.
The second line contains 𝑛 elements of the array, sorted in non-decreasing order. The third line contains 𝑘 queries. 
All array elements and queries are integers, each of which does not exceed 2⋅109 in absolute value.

Output
For each of the 𝑘 queries, print the maximum index of an array element not greater than the given one. If there are none, print 0.
**/

int closest_left(vector<int>& vc, int n, int tar) {
	int ans = 0;
	
	int low = 0, high = n-1;
	while(low <= high) {
		int mid = (low + high)/2;
		if(vc[mid] > tar) {
			high = mid - 1;
		} else {
			ans = mid + 1;
			low = mid + 1;
		}
	}
	return ans;
}

int main() {
	
	int n,k;
	cin >> n >> k;
	vector<int> vc(n);
	for(int i=0; i<n; i++) {
		cin >> vc[i];
	}
	
	while(k--) {
		int tar;
		cin >> tar;
		int ans = closest_left(vc, n, tar);
		cout << ans << '\n';
	}
	
	return 0;
}
