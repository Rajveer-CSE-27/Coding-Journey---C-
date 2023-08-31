/**
Problem Statement : Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. 
                    At a time the frog can climb either one or two steps. A height[N] array is also given. 
                    Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]).
                    We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.
                    
Approach : We will be using recursion because we need to find minimum path out of all possible paths and jaha bhi all possible aya waha
           hum recursion try karenge.
           If we are at stair - i solve for i-1 or i-2 recursively then we need to check which path will be of min value :
                The path from i-1 to i or from i-2 to i.
            Recurrence relation : F(n) = F(n-1) + F(n-2)

Time Complexity = O(2^n) because for each index we will be exploring 2 paths therefore total paths = 2*2*2.....*2 = 2^n
Space Complexity = O(n) : auxillary stack space.

**/

#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& height) {
    if(n == 0) {
        return 0;
        // base case 1
    }
    
    if(n == 1) {
        return abs(height[1] - height[0]);
        // base case 2
    }
    
    int oneBehind = solve(n-1, height);
    int twoBehind = solve(n-2, height);
    
    return min(oneBehind + abs(height[n] - height[n-1]), twoBehind + abs(height[n] - height[n-2]));
}

int main() {
    int N = 6;
    int n = N-1;
    // 0 based indexing
    vector<int> height{30,10,60,10,60,50};
    
    int ans = solve(n,height);
    cout << ans;
    
    return 0;
}
