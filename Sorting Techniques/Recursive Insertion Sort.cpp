/** Recursive Insertion Sort
 	Approach :: Like insertion sort : in each iteration we will have a sorted part of array and then unsorted and we will place first element of unsorted array at its correct position in sorted array
 	Time :: O(n^2) , Space :: O(n) -> auxillary stack space
 **/

#include <iostream>
using namespace std;

void insertionSort(int arr[], int i, int n) {
	
	if(i == n-1) {
		return;
	}
	
	int j  = i+1;
	while(j > 0) {
		if(arr[j] < arr[j-1]) {
			swap(arr[j], arr[j-1]);
			j--;
		} else {
			break;
		}
	}
	
	
	
	insertionSort(arr, i+1, n);
	
	
}

int main() {
	
	int arr[] = {9,7,6,1,0,1,10};
	int n = sizeof(arr)/sizeof(arr[0]); // use this only if array is non empty
	
	insertionSort(arr,0,n);
	
	for(auto it:arr) {
		cout << it << " ";
	}
	
	return 0;
}
