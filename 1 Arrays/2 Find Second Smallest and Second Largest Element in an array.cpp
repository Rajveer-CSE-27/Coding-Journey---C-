/** Find second largest and second smallest element in array
 	Approach 1 : Sorting : Time = O(nlogn) , Space = O(1)
	Approach 2 : 2 times Linear Search : Time = O(n) , Space = O(1)
	Approach 3 : 1 time linear search : Time = O(n) . space O(1)
 **/

#include <bits/stdc++.h>
using namespace std;

pair<int,int> solve1(int arr[], int n) {
	sort(arr,arr+n);
	pair<int,int> ans;
	
	// edge case
	if(n < 2) {
		ans.first = -1;
		ans.second = -1;
		return ans;
	}
	
	ans.first = arr[1];
	ans.second = arr[n-2];
	
	return ans;
}

pair<int , int> solve2(int arr[], int n) {
	pair<int,int> ans;
	// edge case
	if(n < 2) {
		ans.first = -1;
		ans.second = -1;
		return ans;
	}
	
	// first linear search for finding max and min
	int mx=arr[0], mn=arr[0];
	for(int i=1; i<n; i++) {
		if(arr[i] > mx) {
			mx = arr[i];
		}
		if(arr[i] < mn) {
			mn = arr[i];
		}
	}
	
	// second linear search for finding second max and second min
	int smx=arr[0] , smn = arr[0];
	for(int i=1; i<n; i++) {
		if(arr[i] > smx && arr[i] < mx) {
			smx = arr[i];
		}
		
		if(arr[i] < smn && arr[i] > mn) {
			smn = arr[i];
		}
	}
	
	ans.first = smn;
	ans.second = smx;
	
	return ans;
}

pair<int,int> solve3(int arr[], int n) {
	pair<int,int> ans;
	// edge case
	if(n < 2) {
		ans.first = -1;
		ans.second = -1;
		return ans;
	}
	
	int mx = INT_MIN, smx = INT_MIN , mn = INT_MAX, smn = INT_MAX;
	for(int i=0; i<n; i++) {
		if(arr[i] > mx) {
			smx = mx;
			mx = arr[i];
		}
		
		if(arr[i] < mn) {
			smn = mn;
			mn = arr[i];
		}
	}
	
	ans.first = smn;
	ans.second = smx;
	
	return ans;
}

int main() {
	int arr[] = {1,5,9,10,2,0,111};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	pair<int,int> pr;
	
	pr = solve1(arr,n);
	cout << pr.first << " " << pr.second << endl;
	
	pr = solve2(arr,n);
	cout << pr.first << " " << pr.second << endl;

	pr = solve3(arr,n);
	cout << pr.first << " " << pr.second << endl;

	
	return 0;
}
