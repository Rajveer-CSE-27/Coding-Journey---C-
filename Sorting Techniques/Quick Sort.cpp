/** Quick Sort
 	Approach :: Divide and conquer + pivot elementt
 	Time :: O(n^2) worst , O(nlogn) average , Space :: O(n) -> auxillary stack space
 **/

#include <iostream>
using namespace std;

int partition(int arr[], int left, int right) {
	
	// we take first element as the pivot
	int pivot = arr[left];
	
	// we count number of elements less than pivot and place pivot at its correct position
	int cnt = 0; // this will represent pivot index
	for(int i=left+1; i<= right; i++) {
		if(arr[i] <= pivot) {
			cnt++;
		}
	}
	
	cnt += left; // because ab ye count nahi raha ab cnt index ko represent karta hai
	swap(arr[left],arr[cnt]);
	
	// we try to arrange all elements < pivot to left and > pivot to right of pivot
	int i=left, j=right;
	while(i < cnt && j > cnt) {
		while(arr[i] <= pivot) {
			i++;
		}
		while(arr[j] > pivot) {
			j--;
		}
		
		// this condition will only be hit if there is a gadbad element
		if(i < cnt && j > cnt) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	
	return cnt;
	
}

void quickSort(int arr[], int left, int right) {
	
	// base case 
	if(left >= right) {
		return;
	}
	
	int partitionedIndex = partition(arr,left,right);
	
	// call recursively for 2 subParts of array
	quickSort(arr, left, partitionedIndex - 1);
	quickSort(arr, partitionedIndex + 1, right);
}

int main() {
	
	int arr[] = {9,7,6,1,0,1,10};
	int n = sizeof(arr)/sizeof(arr[0]); // use this only if array is non empty
	
	quickSort(arr,0,n-1);
	
	for(auto it:arr) {
		cout << it << " ";
	}
	
	return 0;
}
