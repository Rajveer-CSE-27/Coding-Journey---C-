// Problem :: Print number of  subsequences of the array whose sum is equal to the given sum.
// Solution :: Recursion method using {take/not take} approach. Here we need to count the possible answers so we will use int function approach which will return the number of possible of answers. 
// Time :: O(2^n) because we consider all the possible subsequences hence powerset of n values which is 2^n
// Space :: At any time maximum all (n) elements could be in recusrion stack hence space complexity is O(n)

#include <bits/stdc++.h>
using namespace std;

int printS(int index, int currentSum, int n, int targetSum, int arr[]) {
	// base case will be reaching end of array
	if(index == n) {
		if(currentSum == targetSum) {
			// this will increment the overall answer as we found a potential answer
			return 1;
		}
		
		return 0;
	}
	
	// carry the current element
	currentSum += arr[index];
	int left = printS(index+1, currentSum, n, targetSum, arr);
	// this will contain number of all possibilities of valid subsequence with current element.
	
	// drop the current element
	currentSum -= arr[index];
	int right = printS(index+1, currentSum, n, targetSum, arr);
	// this will contain number of all possibilities of valid subsequence without the current element.
	
	
	return left + right;
	// this will return number of all possibilites of valid subsequence with and without current element
}

int main() {
	int arr[] = {1,1,2};
	int n=3, targetSum = 2;
	
	int ans = printS(0, 0, n, targetSum, arr);
	cout << ans << endl;
	
	
	return 0;
}
