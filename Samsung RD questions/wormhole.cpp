#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/warmholes/problem

masking use karli with recursion
**/

int res = INT_MAX;

int dist(pair<int,int> p1, pair<int,int> p2) {
    int ans = abs(p1.first - p2.first) + abs(p2.second - p1.second);
    return ans;
}

void fun(int mask, pair<int,int> curr, pair<int,int> dest, vector<vector<int>>& worm, int cost, int& n) {
    
    int d = cost + dist(curr, dest);
    res = min(res, d);
    
    int endMask = (1<<n) - 1;
    if(mask == endMask) {
        // all wormholes covered
        return;
    }
    
    for(int hole=0; hole<n; hole++) {
        
        if((mask&(1<<hole)) == 0) { // hole not present in mask
            
            // use front of whole
            int x = dist(curr, {worm[hole][0], worm[hole][1]});
            x += worm[hole][4];
            fun((mask|(1<<hole)), {worm[hole][2], worm[hole][3]}, dest, worm, cost + x, n);
            
            
            // use back of whole
            x = dist(curr, {worm[hole][2], worm[hole][3]});
            x += worm[hole][4];
            fun((mask|(1<<hole)), {worm[hole][0], worm[hole][1]}, dest, worm, cost + x, n);
        }
    }
    
    
}

void solve() {
    int n;
    cin >> n;
    pair<int,int> source, dest;
    cin >> source.first >> source.second;
    cin >> dest.first >> dest.second;
    
    vector<vector<int>> worm(n, vector<int>(5));
    for(int i=0; i<n; i++) {
        for(int j=0; j<5; j++) {
            cin >> worm[i][j];
        }
    }
    
    
    fun(0,source,dest, worm, 0, n);
    
    cout << res;
}

int main() {
    
    int tc;
    cin >> tc;
    while(tc--) {
        solve();
        cout << '\n';
    }
    return 0;
}
