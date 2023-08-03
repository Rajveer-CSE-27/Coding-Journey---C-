/** Recursive Bubble Sort
 	Approach :: Like bubble sort : in each iteration we will have largest element at end of unsorted array.
 				Then call bubble sort on remaining array
 	Time :: O(n^2) , Space :: O(n) -> auxillary stack space
 **/

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
	
	// base case of recursion
	if(n == 1) {
		return;
	}
	
	int i = 0; // will keep index of last element of unsorted subarray
	while(i < n-1) {
		if(arr[i] > arr[i+1]) {
			swap(arr[i],arr[i+1]);
		}
		i++;
	}
	
	bubbleSort(arr,n-1);
}

int main() {
	
	int arr[] = {9,7,6,1,0,1,10};
	int n = sizeof(arr)/sizeof(arr[0]); // use this only if array is non empty
	
	bubbleSort(arr,n);
	
	for(auto it:arr) {
		cout << it << " ";
	}
	
	return 0;
}
