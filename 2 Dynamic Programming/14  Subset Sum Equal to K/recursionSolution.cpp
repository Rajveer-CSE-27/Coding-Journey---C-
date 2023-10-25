/**
Problem Statement : We are given an array ‘ARR’ with N positive integers.
                    We need to find if there is a subset in “ARR” with a sum equal to K. 
                    If there is, return true else return false.
                    
Approach : Use recursion method of pick/not-pick to get the answer.

Time Complexity =  O(2^n) becuase we generate powerset.
Space Complexity = O(n) : auxillary stack space.
**/

#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& vc, int index, int k) {
    if(index == -1) {
        return false;
    }
    if(k == 0) {
        return true;
    }
    bool not_pick = solve(vc, index-1, k);
    bool pick = false;
    if(k >= vc[index]) {
        pick = solve(vc, index-1, k-vc[index]);
    }
    
    return not_pick or pick;
}

int main() {
    
    int n, k;
    cin >> n >> k;
    vector<int> vc(n);
    for(int i=0; i<n; i++) {
        cin >> vc[i];
    }
    
    bool ans = solve(vc,n-1,k);
    (ans) ? cout << "YES\n" : cout << "NO\n";
     
    return 0;
}
