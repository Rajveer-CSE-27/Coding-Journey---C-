// Problem :: Print any one of the subsequences of the array whose sum is equal to the given sum.
// Solution :: Recursion method using {take/not take} approach. Here we need to print only 1 answer so use boolean function technique as soon we find an answer return true else go on returning false.
// Time :: O(2^n) because in worst case we consider all the possible subsequences hence powerset of n values which is 2^n
// Space :: At any time maximum all (n) elements could be in recusrion stack hence space complexity is O(n)

#include <bits/stdc++.h>
using namespace std;

bool printS(int index, int currentSum, int arr[], int n, int targetSum, vector<int>& ds) {
	if(index == n) {
		if(currentSum == targetSum) {
			for(auto it:ds) {
				cout << it << " ";
			}
			cout << endl;
			return true;
		}
		// if sum is not required
		return false;
	}
	
	// carry the current element
	ds.push_back(arr[index]);
	currentSum += arr[index];
	if(printS(index+1, currentSum, arr, n, targetSum, ds) == true) {
		return true;
		// that is if we already found a solution then don't go further.
	}
	
	// drop the current element
	ds.pop_back();
	currentSum -= arr[index];
	if(printS(index+1, currentSum, arr, n, targetSum, ds) == true) {
		return true;
	}
	
	return false;
}

int main() {
	
	int arr[] = {1,1,2};
	int n=3, targetSum = 2;
	vector<int> ds;
	
	printS(0, 0, arr, n, targetSum, ds);
	
	return 0;
}
