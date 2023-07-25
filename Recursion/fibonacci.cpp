#include <bits/stdc++.h>
using namespace std;

void fibIterative(int n) {
	int i=0;
	int j=1;
	int k = 2;
	cout << i << " " << j << " ";
	while(k < n) {
		cout << i + j << " ";
		int temp = j;
		j = j+ i;
		i = temp;
		k++;
	}
	
	
}

int fibRecursive(int n) {
	if(n == 0 || n == 1) {
		return n;
	}
	return fibRecursive(n-1) + fibRecursive(n-2);
	
}

int main() {
	
	int n;
	cin >> n;
	fibIterative(n);
	cout << endl;
	cout << fibRecursive(n) << endl;
	return 0;
}