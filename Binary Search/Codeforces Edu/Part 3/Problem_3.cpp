#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Problem link :: https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/C

Approach :: 
	Looks like Min(Max()) type binary search question.
	Let us say we have a value x that represents minimum distance between 2 cows.
	For the variable x we say that after placing all  k cows in some fashion the distance between any pair of them is >= x.
	
	The variable x has a good-bad sequence :: 111111111000000000000000.
	And we need to find maximum value of x such that it is good.
	
	Hence do binary search.
		
**/

int n,k;
vector<int> stalls;

bool is_good(ll x) {
	// fill k cows such that minimum distance between them is >= x
	
	int cowsFilled = 1;
	int i=1;
	ll dist = 0;
	
	while(i < n) {
		if(dist + stalls[i] - stalls[i-1] < x) {
			dist += (stalls[i] - stalls[i-1]);
			i++;
		} else {
			cowsFilled++;
			dist = 0;
			i++;
		}
	}
	if(cowsFilled >= k) {
		return true;
	}
	return false;
}

int main() {
	
	cin >> n >> k;
	stalls.resize(n);
	for(int i=0; i<n; i++) {
		cin >> stalls[i];
	}
	
	ll low = 0; // 2 cows are always at a distance >= 0 from each other. Hence this is a good value.
	ll high = 2 * 1e9; // if k == 2 and one cow at first possible (0) stall and other cow at last possible (1e9) stall then distance is 1e9 hence  2* (1e9) is sure a bad value.
	
	while(low + 1 < high) {
		ll mid = (low + high)/2;
		if(is_good(mid) == true) {
			low = mid;
		} else {
			high = mid;
		}
	}
	cout << low;
	
	return 0;
}
