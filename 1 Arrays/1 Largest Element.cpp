/** Largest Element in Array
 	Approach 1 : Sorting : Time = O(nlogn) , Space = O(1)
	Approach 2 : Linear Search : Time = O(n) , Space = O(1)
 **/

#include <bits/stdc++.h>
using namespace std;

int solve1(int arr[], int n) {
	if(n == 0) {
		return -1;
	}
	
	sort(arr,arr+n);
	return arr[n-1];
}

int solve2(int arr[], int n) {
	if(n == 0) {
		return -1;
	}
	
	int mx = arr[0];
	for(int i=1; i<n; i++) {
		if(arr[i] > mx) {
			mx = arr[i];
		}
	}
	
	return mx;
}

int main() {
	int arr[] = {1,5,9,10,2,0,111};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	int mx = solve1(arr,n);
	cout << mx << endl;
	
	mx = solve2(arr,n);
	cout << mx << endl;
	
	
	return 0;
}
