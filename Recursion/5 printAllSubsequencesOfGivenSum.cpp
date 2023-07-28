// Problem :: Print all the subsequences of the array whose sum is equal to the given sum.
// Solution :: Recursion method using {take/not take} approach
// Time :: O(2^n) because we consider all the possible subsequences hence powerset of n values which is 2^n
// Space :: At any time maximum all (n) elements could be in recusrion stack hence space complexity is O(n)

#include <bits/stdc++.h>
using namespace std;

void printS(int index, int currentSum, int arr[], int n, int targetSum, vector<int>& ds) {
	// writing the base case of recursion
	// if we reach till end of array
	if(index == n) {
		if(currentSum == targetSum) {
			for(auto it:ds) {
				cout << it << " ";
			}
			cout << endl;
		}
		
		return;
	}
	
	// adding the current element to the subsequence and working with it in future
	ds.push_back(arr[index]);
	currentSum += arr[index];
	printS(index+1, currentSum, arr, n, targetSum, ds);
	
	// removing the element and then working without it in future
	ds.pop_back();
	currentSum -= arr[index];
	printS(index+1, currentSum, arr, n, targetSum, ds);
}

int main() {
	int arr[] = {1,2,3,1,4,2,1,3};
	int n = 8 , targetSum = 4;
	vector<int> ds; // we maintain a datastructure here vector for storing the values to print
	
	printS(0, 0, arr, n, targetSum, ds);
	
	return 0;
}
