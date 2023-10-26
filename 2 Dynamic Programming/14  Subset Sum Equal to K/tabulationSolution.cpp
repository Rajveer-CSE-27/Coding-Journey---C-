/**
Problem Statement : We are given an array ‘ARR’ with N positive integers.
                    We need to find if there is a subset in “ARR” with a sum equal to K. 
                    If there is, return true else return false.
                    
Approach : Use tabulation to save space.

Time Complexity =  O(n*k) becuase we will consider all possible sums from all indices.
Space Complexity = O(n*k) dp space
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
    //bottoms up dp
    vector<vector<bool>> dp(n, vector<bool>(k+1, false));
    for(int i=0; i<n; i++) {
        dp[i][0] = true;
        // base case 
    }
    
    dp[0][vc[0]] = true; // base case 2 i.e we reach first index and requied sum is equal to value at 1st index.
    
    for(int i=1; i<n; i++) {
        for(int target = 1; target <=k; target++) {
            bool not_pick = dp[i-1][target];
            bool pick = false;
            if(target >= vc[i]) {
                pick = dp[i-1][target - vc[i]];
            }  
            dp[i][target] = not_pick or pick;
        }
    }
    cout << dp[n-1][k] << endl;
}
