#include <bits/stdc++.h>
using namespace std;

void reverseArrayIterative(int arr[] , int n) {
	int i=0 , j=n-1;
	while(i < j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;
		j--;
	}
	
}

void reverseArrayRecursive(int arr[] , int l , int r) {
	if(l >= r) {
		return;
	}
	int temp = arr[l];
	arr[l] = arr[r];
	arr[r] = temp;
	reverseArrayRecursive(arr , l+1 , r-1);
}

int main() {
	
	int arr[6] = {1,2,5,3,7,10};
	
	reverseArrayIterative(arr , 6);
	for(int i=0; i<6; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	reverseArrayRecursive(arr , 0 , 5);
	for(int i=0; i<6; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	return 0;
}