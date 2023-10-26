/**
Problem Statement : We are given an array ‘ARR’ with N positive integers. 
                    We need to find if we can partition the array into two subsets, 
                    such that the sum of elements of each subset is equal to the other.
                    
Approach :  Using recursion to solve. This is same as subset sum problem. We need to find
            a subset having sum = (sum of array)/2. If we successfully find then the sum of
            rest of the elements will be (sum of array)/2 and hence we get the required answer.

Time Complexity =  O(2^n)

Space Complexity = O(n) 
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
        pick = solve(vc, index - 1, k - vc[index]);
    }
    return not_pick or pick;
}

int main() {
    
    int n, sm = 0;
    cin >> n;
    vector<int> vc(n);
    for(int i=0; i<n; i++) {
        cin >> vc[i];
        sm += vc[i];
    }
    bool ans = false;
    if(sm%2 == 0) {
        int k = sm/2;
        ans = solve(vc, n-1, k);
    }
    
    (ans) ? cout << "YES\n" : cout << "NO\n";
    
}
