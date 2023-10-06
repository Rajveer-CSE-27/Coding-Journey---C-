/**
Problem Statement : Given two values M and N, which represent a matrix[M][N]. 
                    We need to find the total unique paths from the top-left cell (matrix[0][0]) to the rightmost cell (matrix[M-1][N-1]).
                    At any cell we are allowed to move in only two directions:- bottom and right.
                    
Approach : We will be using recursion because we need to find number of paths. So cell (i,j) would only be visited by cells (i-1,j) , (i,j-1).
           So number of paths till cell (i,j) = number of paths till (i-1,j) + till (i,j-1).
           F(i,j) = F(i-1,j) + F(i,j-1)

Time Complexity = O(2^(m+n)) because for each index we will be exploring 2 paths therefore total paths = 2*2*2.....*2 = 2^n
Space Complexity = O(n+m) : auxillary stack space.
**/

#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int x, int y) {
    
    if(x == 0 or y == 0) {// base case because any element of 1st row or 1st column could be reached by only 1 path.
        return 1;
    }
    
    return uniquePaths(x-1,y) + uniquePaths(x,y-1);
    
}


int main() {
    
    int m,n;
    cin >> m >> n;
    int ans = uniquePaths(m-1,n-1);
    
    cout << ans;
    return 0;
}

