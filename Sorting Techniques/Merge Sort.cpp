/** Merge Sort
 	Approach :: Divide and conquer
 	Time :: O(nlogn) , Space :: O(n)
 **/

#include <iostream>
using namespace std;


void merge(int arr[], int left, int mid, int right) {
	int leftArr[mid - left + 1];
	int rightArr[right - mid];
	
	for(int i=0; i< mid - left + 1; i++) {
		leftArr[i] = arr[left + i];
	}
	
	for(int i=0; i<right - mid; i++) {
		rightArr[i] = arr[mid + i + 1];
	}
	
	int i=0, j=0, k=left;
	while(i < mid - left + 1 && j < right - mid) {
		if(leftArr[i] <= rightArr[j]) {
			arr[k] = leftArr[i];
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
		k++;
		j++;
	}
}

void mergeSort(int arr[], int left, int right) {
	if(left >= right) {
		// base case for recursion if we are left with single element
		return;
	}
	int mid = left + (right - left)/2;
	
	// recursively call for 2 parts of array
	mergeSort(arr,left,mid);
	mergeSort(arr,mid+1,right);
	
	// then merge those sorted parts 
	merge(arr,left,mid,right);
	
}

int main() {
	
	int arr[] = {9,7,6,10,1,0,1,10};
	int n = sizeof(arr)/sizeof(arr[0]); // use this only if array is non empty
	
	mergeSort(arr,0,n-1);
	
	for(auto it:arr) {
		cout << it << " ";
	}
	
	return 0;
}
