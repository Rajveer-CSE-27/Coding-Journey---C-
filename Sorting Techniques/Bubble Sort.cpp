/** Bubble sort
 	Approach :: Compare adjacent values and swap if larger element is before smaller one and go on 
 				continuing this till end of array.
 				At each iteration we will have maximum element of unsorted part at the end of unsorted part.
 	Time :: O(n^2) , Space :: O(1)
 **/

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
	int end = n-1; // this will represent last index of unsorted array
	
	while(end >= 0) {
		int i=0;
		while(i < end-1) {
			if(arr[i] > arr[i+1]) {
				swap(arr[i],arr[i+1]);
			}
			i++;
		}
		end--;
	}
	
}

int main() {
	
	int arr[] = {9,7,6,10,1,0,11,10};
	int n = sizeof(arr)/sizeof(arr[0]); // use this only if array is non empty
	
	bubbleSort(arr,n);
	
	for(auto it:arr) {
		cout << it << " ";
	}
	
	return 0;
}
