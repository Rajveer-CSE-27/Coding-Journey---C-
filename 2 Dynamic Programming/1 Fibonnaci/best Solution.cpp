/** 
 Print nth Fibonnaci number
 Using some fixed number of variables.
 Approach :: We observe that instead of creating a container of size n everytime we
            can just solve the problem using fixed number of variables hence reducing 
            space complexity efficiently.
**/

/** 
    Time Complexity = O(n) , because we need to iterate from 2 to n th element once.
                             
    Space Complexity = O(1) , best space complexity for fibonnaci problem
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    int prev2 = 0, prev = 1, curr;
    // the first 2 terms of fibonnaci series
    
    if(n <= 1) {
        curr = n;
    }
    
    for(int i=2; i<=n; i++) {
        curr = prev2 + prev;
        prev2 = prev;
        prev = curr;
    }
    
    cout << curr;
    
    return 0;
}
