#include <bits/stdc++.h>
using namespace std;

/**
Implement a binary search algorithm.

Input
The first line of the input contains integers 𝑛 and 𝑘 (1≤𝑛, 𝑘≤105), the length of the array and the number of queries.
The second line contains 𝑛 elements of the array, sorted in non-decreasing order. 
The third line contains 𝑘 queries. All array elements and queries are integers, each of which does not exceed 109 in absolute value.

Output
For each of the 𝑘 queries print YES in a separate line if this number occurs in the array, and NO otherwise.

**/

bool binary_search(vector<int>& vc, int n, int tar) {
	if(n == 0) {
		return false;
	}
	int low = 0, high = n-1;
	
	while(low <= high) {
		int mid = (low + high)/2;
		if(vc[mid] == tar) {
			return true;
		} else if(vc[mid] < tar) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return false;
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
		if(binary_search(vc, n, tar) == true) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
	return 0;
}
