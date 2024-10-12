#include <bits/stdc++.h>
using namespace std;
#define ll long long


/**

https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/fisherman/problem

Recursion but dhyan se
Constraints are very low

**/

int n;
vector<pair<int,int>> gate;
int ans = INT_MAX;

vector<bool> vis;

int findLeft(int curr) {
	// positions start from 1 to n
    while(curr > 0) {
        if(vis[curr] == false) {
            return curr;
        }
        curr--;
    }
    return INT_MAX;
}

int findRight(int curr) {
    while(curr <= n) {
        if(vis[curr] == false) {
            return curr;
        }
        curr++;
    }
    return INT_MAX;
}


void fun(int g1, int g2, int g3, int cost, int g) {
	
	if(cost > ans) {
		return;
		// this will not lead to a better answer
	}
	
	if(gate[g].second == 0) {
		
		if(g == g1) {
			g = g2;
			// now open gate 2
		} else if(g == g2) {
			g = g3;
			// now open gate 3
		} else {
			ans = min(ans, cost);
			return;
			// all fishermen explored
		}
	}
	
	
	// current fishermen will see nearest locations on left and right
	int pos = gate[g].first;
	
	int l = findLeft(pos), r = findRight(pos);
	
	int dist_l = 1 + abs(pos - l); // adding 1 to travel from gate to current pos
	int dist_r = 1 + abs(pos - r);
	
	if(dist_l < dist_r) {
		// current fishermen will go to left
		vis[l] = true;
		gate[g].second--;
		fun(g1,g2,g3, cost + dist_l, g);
		
		vis[l] = false;
		gate[g].second++;
		
	} else if(dist_r < dist_l) {
		// current fishermen will go to right
		
		vis[r] = true;
        gate[g].second--;
        fun(g1,g2,g3, cost + dist_r, g);
        gate[g].second++;
        vis[r] = false;
	} else {
		
		// explore both 
		vis[l] = true;
		gate[g].second--;
		fun(g1,g2,g3, cost + dist_l, g);
		
		vis[l] = false;
		gate[g].second++;
		
		vis[r] = true;
        gate[g].second--;
        fun(g1,g2,g3, cost + dist_r, g);
        gate[g].second++;
        vis[r] = false;
		
	}
	
}

int main() {   

	cin >> n;
	vis.resize(n+1, false); // to keep a track whether a spot is occupied or not
	
	gate.resize(3);
	
	for(int i=0; i<3; i++) {
		cin >> gate[i].first;
		// position of gate
	}
	for(int i=0; i<3; i++) {
		cin >> gate[i].second;
		// number of fishermen's
	}
	
	// all permutations of 1,2,3
	fun(0,1,2, 0, 0);
	fun(0,2,1, 0, 0);
    fun(1,0,2, 0, 1);
    fun(1,2,0, 0, 1);
    fun(2,0,1, 0, 2);
    fun(2,1,0, 0, 2);
    
    cout << ans;
 	
    return 0;
}
