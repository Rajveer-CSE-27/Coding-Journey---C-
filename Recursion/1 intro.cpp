#include <bits/stdc++.h>
using namespace std;

void printName5Times(string s , int n) {
	if(n == 5) {
		return;
	}
	cout << s << endl;
	printName5Times(s , n+1);
}

void print1ToNBacktrack(int n) {
	if(n == 0) {
		return;
	}
	print1ToNBacktrack(n-1);
	cout << n << " ";
	
}

void printNto1Backtrack(int n) {
	if(n == 0) {
		return;
	}
	cout << n << " ";
	printNto1Backtrack(n-1);
}

void print1ToN(int n , int i) {
	if(i == n+1) {
		return;
	}
	cout << i << " ";
	print1ToN(n , i+1);
}

void printNTo1(int n , int i) {
	if(i == n+1) {
		return;
	}
	printNTo1(n , i+1);
	cout << i << " ";
}

int sumOfNTerms(int n) {
	if(n == 0) {
		return 0;
	}
	return n + sumOfNTerms(n-1);
}

int factorialOfN(int n) {
	if(n == 1 || n == 0) {
		return n;
	}
	return n*factorialOfN(n-1);
}

int main() {
	
	//problem 1
	printName5Times("Rajveer" , 0);
	// problem 2
	print1ToNBacktrack(5);
	cout << endl;
	// problem 3
	printNto1Backtrack(5);
	cout << endl;
	//problem 4
	print1ToN(6 , 1);
	cout << endl;
	//problem 5
	printNTo1(6 , 1);
	cout << endl;
	//problem 6
	int x = sumOfNTerms(5);
	cout << x << endl;
	//problem 7
	x = factorialOfN(6);
	cout << x << endl;
	
	return 0;
}
