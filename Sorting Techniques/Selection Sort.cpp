/** Selection sort
 Approach :: At each iteration select the minimum element from the unsorted part of array
			       and swap it with the first  element of the unsorted array.
Time complexity = O(n^2) , Space = O(1) **/

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
	int i=0; // will give index of beginning of unsorted array
	
	while(i < n) {
		int mn = arr[i] , mnIndexTemp = i;
		
		for(int j=i+1; j<n; j++) {
			if(arr[j] < mn) {
				mn = arr[j];
				mnIndexTemp = j;
			}
		}
		swap(arr[i], arr[mnIndexTemp]);
		i++;
		
	}
}

int main() {
	
	int arr[] = {9,7,6,10,1,0,11,10};
	int n = sizeof(arr)/sizeof(arr[0]); // use this only if array is non empty
	
	selectionSort(arr,n);
	
	for(auto it:arr) {
		cout << it << " ";
	}
	
	return 0;
}
