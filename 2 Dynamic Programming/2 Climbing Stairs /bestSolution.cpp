/**
Problem Statement : Given a number of stairs. 
                    Starting from the 0th stair we need to climb to the “Nth” stair. 
                    At a time we can climb either one or two steps. 
                    We need to return the total number of distinct ways to reach from 0th to Nth stair.

Approach : Convert the previous Tabulation solution to most space efficient solution.
           
Time Complexity : O(n) , maximum it computes once for each stair from 0 to N.
Space Complexity : O(1)
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    
    int prev2 = 1;
    int prev = 1;
    int curr;
    
    
    if(n <= 1) {
        curr = 1;
        // edge cases.
    }
    
    for(int i=2; i<=n; i++) {
        curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    
    cout << curr;
    return 0;
}
