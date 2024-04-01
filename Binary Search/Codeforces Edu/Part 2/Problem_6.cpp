
#include <bits/stdc++.h>
using namespace std;
#define ld long double

/**
Problem link :: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/F

Approach :: 
	The variable to delete x number ofletters deleted such that our remaining string stays valid follows sequence ::
			111111111100000000000......
			
	Hence need to find maximum x such that x is good.
	Binary search

**/

string t,p;
vector<int> vc;

bool is_good(int x) {
	// x is the number of characters deleted in the given sequence
	
	string temp = t;
	for(int i=0; i<x; i++) {
		temp[vc[i]-1] = '*';
	}
	string temp2 = "";
	for(int i=0; i<temp.length(); i++) {
		if(temp[i] != '*') {
			temp2 += temp[i];
		}
	}
	int i=0, j=0;
	while(i < temp2.length() and j < p.length()) {
		if(temp2[i] == p[j]) {
			i++;
			j++;
		} else {
			i++;
		}
	}
	
	if(j == p.length()) {
		return true;
	}
	return false;
}

int main() {
	
	cin >> t;
	cin >> p;
	vc.resize(t.length());
	for(int i=0; i<t.length(); i++) {
		cin >> vc[i];
	}
	
	int low = 0; // if we delete 0 characters then we can surely obtain p from t therefore 0 is first good value
	int high = t.length(); // if we delete all characters from t then we can never obtain p from t therefore this is a bad value.
	
	while(low + 1 < high) {
		int mid = (low + high)/2;
		if(is_good(mid) == true) {
			low = mid;
		} else {
			high = mid;
		}
	}
	
	cout << low;
	
	return 0;
}
