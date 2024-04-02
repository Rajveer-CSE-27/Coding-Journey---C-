#include <bits/stdc++.h>
using namespace std;


int n;
vector<double> pos, velocity;
/**
Problem link :: https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/A

Approach :: Min(Max()) binary search approach.

	Let xi be the position of ith person and vi be the speed of same.
	Let we need to accumulate everyone at location x
	Then time for 1 person to go from its current position to x = abs(xi - x)/vi
	Total time required for all person to gather at x = max(abs(xi - x)/vi) for all i. Because all can move parallely.
	
	
	So, let we have a time t. And we need to find whether all persons can gather at any position within time t.
	That is for a given t we check that if it is possible to find a valid location x such that all people could gather at x within time t or not?
	
	hence we need : max(abs(xi - x)/vi) <= t [now for a given t let us calculate x]
	
	max(abs(xi - x)/vi) <= t for all i
	hence :: abs(xi - x)/vi <= t for all i
	abs(xi - x) <= t * vi for all i
	
	x belongs to [xi - t*vi, xi + t*vi] for all i;
	hence these are multiple intervals accross i's and we need to find a valid intersection of all these intervals.
	If a valid intersection exists then a valid x exists such that all people can gather at x within time t.
	Hence t could be a valid answer.
	And we need to find minimum t such that a valid x exists.
	
	
	Note that the variable t follows a bad-good sequence :: 0000000000111111111111111......
	Hence we perform binary search on the value of t and find the first good t. that is the minimum t.
	
	Because here t is a real number hence we will apply the method of binary search on real number.
	
**/

bool is_good(double t) {
	
	// let final intersection of all intervals = [start, finish]
	// find the greatest start value and least finish value
	
	double start = INT_MIN, finish = INT_MAX;
	
	for(int i=0; i<n; i++) {
		double startTemp = pos[i] - t*velocity[i];
		double finishTemp = pos[i] + t*velocity[i];
		
		start = max(start, startTemp);
		finish = min(finish, finishTemp);
	}
	
	if(start <= finish) {
		return true;
	}
	return false;
}


int main() {
	
	cin >> n;
	pos.resize(n);
	velocity.resize(n);
	for(int i=0; i<n; i++) {
		cin >> pos[i] >> velocity[i];
	}
	
	
	// checking if all are on the same position. Edge case;
	bool check = true;
	for(int i=1; i<n; i++) {
		if(pos[i] != pos[0]) {
			check = false;
		}
	}
	if(check == true) {
		cout << 0;
		return 0;
	}
	
	double low = 0; // this is definitely a bad value because we cannot bring everyone together in zero time
	double high = 2 * (1e9); // a good value based upon constraints. Let all travel 2 * (1e9) distance with speed = 1. Hence max time is this only
	
	for(int i=0; i<100; i++) { // binary search on real numbers
		
		double mid = (low + high)/2;
		if(is_good(mid) == true) {
			high = mid;
		} else {
			low = mid;
		}
		
	}
	
	cout << setprecision(12) << high;
	
	
	return 0;
}
