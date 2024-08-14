// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long


/**
https://www.geeksforgeeks.org/travelling-salesman-problem-using-dynamic-programming/

https://www.geeksforgeeks.org/problems/travelling-salesman-problem2732/1


Problem :: Given a complete graph with weighted edges (as an adjacency matrix) what is the Hamiltonian cycle (path that visits every node once) of
minimum cost?
			Note :: you do have to return to original node

Appoach :: 
	1. Brute force :: O(n!) :: check all possible paths
	2. DP Approach : O(n * n * 2^n) time and O(n * 2^n) space

DP Approach :: 	
	
	dp state :: (lastVisitedCity, setofcities)
	
	lastVisitedCity could be any city out of n cities.
	setofCities is the powerset of cities visited till now 
	Hence space :: n * 2^n
**/

int tsp(int mask, int currentCity, vector<vector<int>>& cost, vector<vector<int>>& dp) {
	// mask represents set of cities that we visited
	
	int n = cost.size();
	
	int endMask = (1<<n) - 1;
	
	if(mask == endMask) {
		// we visited all cities
		// now just go back from current city to source city
		return cost[currentCity][0];
	}
	
	if(dp[mask][currentCity] != -1) {
		return dp[mask][currentCity];
	}
	
	int ans = INT_MAX;
	
	for(int city = 0; city < n; city++) {
		
		// if the city has not been visited
		if((mask & (1<<city)) == 0) {
			
			// visit the city from currentCity and go on further from there
			int tempAns = cost[currentCity][city] + tsp(mask|(1<<city), city, cost, dp);
			ans = min(ans, tempAns);
		}
	}
	
	return dp[mask][currentCity] = ans;
}


int main() {
	
	int n;
	cin >> n;
	vector<vector<int>> cost(n, vector<int>(n));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> cost[i][j];
		}
	}
	
	vector<vector<int>> dp((1<<n) + 5, vector<int>(n, -1));
	// dp[i][j] = we have currently visited set of cities represented by mask = i and we are currently at city j
	
	// we select city 0 as source so we already visited it.
	int ans = tsp(1, 0, cost, dp); 
	
	cout << ans;
	return 0;
}
