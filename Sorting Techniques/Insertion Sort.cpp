/** Insertion sort
 	Approach :: At each iteration we will insert the first element of the unsorted array in its correct position 
 				in sorted array.
 	Time :: O(n^2) , Space :: O(1)
 **/

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
	int i = 1; // this will index the first element of unsorted array
	
	while(i < n) {
		int j = i;
		while(j > 0) {
			if(arr[j] < arr[j-1]) {
				swap(arr[j],arr[j-1]);
				j--;
			} else {
				break;
			}
		}
		i++;
	}
	
}

int main() {
	
	int arr[] = {9,7,6,10,1,0,1,10};
	int n = sizeof(arr)/sizeof(arr[0]); // use this only if array is non empty
	
	insertionSort(arr,n);
	
	for(auto it:arr) {
		cout << it << " ";
	}
	
	return 0;
}
