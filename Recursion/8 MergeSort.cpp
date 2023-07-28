//Problem :: Merge Sort
// Solution :: Recursion + divide and conquer
// Time Complexity :: O(nlog(n)) 
// Space Complexity :: O(n)

#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
	// creating 2 subarrays
	int leftArr[mid - left + 1], rightArr[right - mid];
	
	// putting values of left half and right half of original array in these subArrays
	for(int i=0; i<mid - left + 1; i++) {
		leftArr[i] = arr[left + i];
	}
	for(int i=0; i<right - mid; i++) {
		rightArr[i] = arr[mid + i + 1];
	}
	
	// now comparing the values of two half arrays and putting them in original array in sorted order
	int i=0, j=0, k=left;
	while(i < mid - left + 1 && j < right - mid) {
		if(leftArr[i] <= rightArr[j]) {
			arr[k] =leftArr[i];
			i++;
			
		} else {
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}
	
	while(i < mid - left + 1) {
		arr[k] = leftArr[i];
		i++;
		k++;
	}
	
	while(j < right - mid) {
		arr[k] = rightArr[j];
		j++;
		k++;
	}
	
}

void mergeSort(int arr[] , int left, int right) {
	// base case
	if(left >= right) {
		return;
	}
	
	int mid = left + (right - left)/2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid+1, right);
	
	merge(arr, left, mid, right);
}


int main() {
	
	int arr[] = {4,5,3,2,0,4,8,11};
	int n = 8;
	
	mergeSort(arr, 0, n-1);
	
	for(auto it:arr) {
		cout << it << " ";
	}
	cout << endl;
	
	return 0;
}
