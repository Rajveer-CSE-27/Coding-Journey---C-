/**
Problem Statement : Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. 
                    At a time the frog can climb either one or two steps. A height[N] array is also given. 
                    Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]).
                    We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.
                    
Approach : We will try to save space beyond tabulation solution.

Time Complexity = O(n) because for each index we will be computing answer only once
Space Complexity = O(1)

**/

#include <bits/stdc++.h>
using namespace std;



int main() {
    int N = 6;
    int n = N-1;
    // 0 based indexing
    vector<int> height{30,10,60,10,60,50};
    
    int prev2 = 0; // initially representing 0th index/stair
    int prev = abs(height[1] - height[0]); // initially representing 1st index
    // base cases of memoization
    
    int curr;
    if(n == 0) {
        curr = prev2;
    }
    
    if(n == 1) {
        curr = prev;
    }
    
    
    for(int i=2; i<=n; i++) {
        curr = min(prev + abs(height[i] - height[i-1]), prev2 + abs(height[i] - height[i-2]));
        prev2 = prev;
        prev = curr;
    }
    cout << curr;
    return 0;
}
