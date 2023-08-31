/**
Problem Statement : Given a number of stairs. 
                    Starting from the 0th stair we need to climb to the “Nth” stair. 
                    At a time we can climb either one or two steps. 
                    We need to return the total number of distinct ways to reach from 0th to Nth stair.

Approach : We fill apply funda of DP and we see that this problem can be solved using recursion.
           So first solving it using recursion. We see that any stair can be either reached by
           (i-1)th stair or (i-2)th stair. So summing up all the possibilites will give us answer.
           
Time Complexity : O(2^n) because we are applying recursion with recurrence relation : F(n) = F(n-1) + F(n-2)
Space Complexity : O(n) recursion auxillary stack space 
**/

#include <bits/stdc++.h>
using namespace std;

int stairs(int n) {
    if(n <= 1) {
        // edge case we can reach 0th stair in only 1 way and 1st stair in only 1 way
        return 1;
    }
    
    return stairs(n-1) + stairs(n-2);
}

int main() {
    int n;
    cin >> n;
    
    int ans = stairs(n);
    cout << ans;
    return 0;
}
