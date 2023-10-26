/**
Problem Statement : We are given an array ‘ARR’ with N positive integers.
                    We need to find if there is a subset in “ARR” with a sum equal to K. 
                    If there is, return true else return false.
                    
Approach : More space optimization than tabulation.

Time Complexity =  O(n*k) becuase we will consider all possible sums from all indices.
Space Complexity = O(k) dp space
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    
    int n, k;
    cin >> n >> k;
    vector<int> vc(n);
    for(int i=0; i<n; i++) {
        cin >> vc[i];
    }
    vector<bool> dp(k+1, false);
    dp[0] = true;
    dp[vc[0]] = true; // base case 2 i.e we reach first index and requied sum is equal to value at 1st index.
    
    for(int i=1; i<n; i++) {
        vector<bool> tempDp(k+1, false);
        tempDp[0] = true;
        for(int target = 1; target <=k; target++) {
            bool not_pick = dp[target];
            bool pick = false;
            if(target >= vc[i]) {
                pick = dp[target - vc[i]];
            }
            tempDp[target] = not_pick or pick;
        }
        dp = tempDp;
    }
    
    (dp[k]) ? cout << "YES\n" : cout << "NO\n";
}
