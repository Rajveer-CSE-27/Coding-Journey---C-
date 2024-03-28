#include <bits/stdc++.h>
using namespace std;

/**
You are given an array 𝑎 of 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛.
Your task is to response to the queries like "How many numbers' values are between 𝑙 and 𝑟?".

Input
The first line of the input contains 𝑛 — the length of the array (1≤𝑛≤105).
The second line contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (−109≤𝑎𝑖≤109).
The third line contains integer 𝑘 — the number of queries (1≤𝑘≤105).
The following 𝑘 lines contain a pair of integers 𝑙 𝑟 — query, described above (−109≤𝑙≤𝑟≤109).

Output
The output must consist of 𝑘 integers — responses for the queries.
**/

int left(vector<int>& vc, int n, int l) {
	int ans = -1;
	
	int low = 0, high = n-1;
	while(low <= high) {
		int mid = (low + high)/2;
		
		if(vc[mid] < l) {
			low = mid + 1;
		} else {
			ans = mid;
			high = mid - 1;
		}
	}
	return ans;
}

int right(vector<int>& vc, int n, int r) {
	int ans = -1;
	int low = 0, high = n-1;
	
	while(low <= high) {
		int mid = (low + high)/2;
		
		if(vc[mid] > r) {
			high = mid - 1;
		} else {
			ans = mid;
			low = mid + 1;
		}
	}
	return ans;
}

int main() {
	
	int n,k;
	cin >> n;
	vector<int> vc(n);
	for(int i=0; i<n; i++) {
		cin >> vc[i];
	}
	cin >> k;
	sort(vc.begin(), vc.end());
	
	while(k--) {
		int l, r;
		cin >> l >> r;
		
		int leftIndex = left(vc,n,l), rightIndex = right(vc,n,r);
		if(leftIndex == -1 or rightIndex == -1) {
			cout << 0 << '\n';
		} else {
			cout << (rightIndex - leftIndex + 1) << '\n';
		}
		
	}
	
	return 0;
}
