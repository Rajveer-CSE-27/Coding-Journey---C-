#include <bits/stdc++.h>
using namespace std;


// this function returns the index of the pivot element by placing all other elements acc to pivot elements
int partition(int arr[] , int left, int right) {
	// we are taking first element as pivot
	int pivot = arr[left];
	
	// counting number of elements <= pivot
	int cnt=0;
	for(int i=left+1; i<= right; i++) {
		if(arr[i] <= pivot) {
			cnt++;
		}
	}
	// IMP step of recursion
	int pivotIndex = left + cnt;
	
	// place the pivot element at its correct position
	swap(arr[pivotIndex] , arr[left]);
	
	// place all other elements accordingly
	int i=0, j=right;
	
	while(i < pivotIndex && j > pivotIndex) {
		while(arr[i] <= pivot) {
			i++;
		}
		
		while(arr[i] > pivot) {
			j--;
		}
		
		// jaise hi galat element dikha swap kardo
		if(i < pivotIndex && j > pivotIndex) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	return pivotIndex;	
		
}


void quickSort(int arr[], int left, int right) {
	// base case 
	if(left >= right) {
		return;
	}
	
	int pivotIndex = partition(arr, left, right);
	
	// now the element at pivotIndex is placed at its position and all elements <pivot are on lefft and all >pivot are on right
	quickSort(arr, left, pivotIndex - 1);
	quickSort(arr, pivotIndex + 1, right);
}

int main() {
	int arr[] = {3,2,1};
	int n = 3;
	
	quickSort(arr , 0 , n-1);
	
	for(auto it: arr) {
		cout << it << " ";
	}
	
	return 0;
}
