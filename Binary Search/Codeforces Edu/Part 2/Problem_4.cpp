
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Problem Link :: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D

Approach ::
	Here we observe that the time variable x has a bad-good sequence.
	 00000000000111111111111111.
	 We need to find min good x hence we apply binary search.
		
**/

int m,n;
vector<vector<int>> vc;


bool is_good(int x) {
	
	
	int totalBalloons = 0;
	for(int i=0; i<n; i++) {
		int mul = (vc[i][0] * vc[i][1]);
		int stTime = mul + vc[i][2];
		int totalSets = x/stTime;
		int balloons = totalSets*vc[i][1];
		int timeLeft = x%stTime;
		if(timeLeft >= mul) {
			timeLeft = mul;
		}		
		balloons += timeLeft/vc[i][0];
		
		totalBalloons += balloons;
	}
	
	if(totalBalloons >= m) {
		return true;
	}
	return false;
}

int main() {
	cin >> m >> n;
	vc.resize(n, vector<int>(3));
	
	for(int i=0; i<n; i++) {
		cin >> vc[i][0] >> vc[i][1] >> vc[i][2];
	}
	
	if(m == 0) { // edge case
		cout << 0 << '\n';
		for(int i=0; i<n; i++) {
			cout << 0 << " ";
		}
		return 0;
	}
	
	int low = 0; // this is definitely bad because we cannot inflate m balloons in 0 time
	int high = 200*m; // worst case occurs if n=1 that is only 1 inflator and takes 100 sec to inflate 1 baloon and takes 100sec rest after it and does this after each baloon.
	
	while(low + 1 < high) {
		int mid = (low + high)/2;
		if(is_good(mid) == true) {
			high = mid;
		} else {
			low = mid;
		}
	}
	
	cout << high << '\n';
	
	int left = m;
	for(int i=0; i<n; i++) {
		int mul = (vc[i][0] * vc[i][1]);
		int stTime = mul + vc[i][2];
		int totalSets = high/stTime;
		int balloons = totalSets*vc[i][1];
		int timeLeft = high%stTime;
		if(timeLeft >= mul) {
			timeLeft = mul;
		}		
		balloons += timeLeft/vc[i][0];
		
		if(left >= balloons) {
			cout << balloons << " ";
			left -= balloons;
		} else {
			cout << left << " ";
			left = 0;
		}
	}
	
	return 0;
}
