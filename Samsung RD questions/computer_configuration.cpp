#include <bits/stdc++.h>
using namespace std;
#define ll long long


/**
https://github.com/s-kachroo/SamsungPractice/blob/master/Two%20Problems%20Mixed.cpp

constraints of n is very low.
Hence classic recursion lagegi. That is explore all possibilities.

Not that you can take atmost 3 different configurations
But one configurations could be taken many times.

**/

void fun(int index, int& n, vector<vector<int>>& configuration, int D, int E, int F, int& d, int& e, int cnt, int& ans, int cost) {
	
	if(index == n or cnt == 3) {
		// selling remaining inventories
		cost += D*d + E*e;
		ans = max(ans, cost);
		return;
	}
	
	// not taking current configuration
	fun(index + 1, n, configuration, D, E, F, d, e, cnt, ans, cost);
	
	// taking current config curr number of times
	int curr = 1;
	while(true) {
		
		if(D - configuration[index][0]*curr >= 0 and E - configuration[index][1]*curr >= 0 and F - configuration[index][2]*curr >= 0) {
			fun(index + 1, n, configuration, D - configuration[index][0]*curr, E - configuration[index][1]*curr, F - configuration[index][2]*curr, d, e, cnt+1, ans, cost + configuration[index][3]*curr);
			curr++;
		} else {
			break;
		}
		
	}
	
} 

int main() {   


	int tc;
	cin >> tc;
	
	while(tc--) {
		int D,E,F,d,e;
		cin >> D >> E >> F >> d >> e;
		int n;
		cin >> n;
		
		vector<vector<int>> configuration(n, vector<int>(4));
		for(int i=0; i<n; i++) {
			cin >> configuration[i][0] >> configuration[i][1] >> configuration[i][2] >> configuration[i][3];
		}
		
		int ans = 0;
		fun(0, n, configuration, D, E, F, d, e, 0, ans, 0);
		
		cout << ans << '\n';
		
	}
 
    return 0;
}
