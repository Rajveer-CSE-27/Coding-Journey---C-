// || जय जय जय बजरंग बली ||


// https://www.youtube.com/watch?v=685x-rzOIlY&list=PLb3g_Z8nEv1icFNrtZqByO1CrWVHLlO5g&index=4

/**
Problem Statement

Let there be N workers and N jobs. 
Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment.
It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent 
in such a way that the total cost of the assignment is minimized.

Input Format
Number of workers and job: N
Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

Sample Input
4

[
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4
]

Sample Output
13

Constraints
N <= 20


**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> dp;
vector<vector<int>> matrix;

int fun(int worker, int subset, int& n) {
    // this fun will give us minimum cost required to complete the tasks represented by bitmask : subset if we are at current worker.
    // NOTE:: this means that we have assigned all previous workers some task already
    
    if(subset == 0) {
        // no task left
        return 0;
    }
    
    if(dp[worker][subset] != -1) {
        return dp[worker][subset];
    }
    
    int ans = INT_MAX;
    for(int bit_no = 0; bit_no < n; bit_no++) {
        
        if(subset & (1 << bit_no)) {
            int val = matrix[worker - 1][bit_no];
            
            // remove the current bit for the nextSubset
            int nextSubset = (subset ^ (1 << bit_no));
            val += fun(worker + 1, nextSubset, n);
            
            ans = min(ans, val);
        }
    }
    
    return dp[worker][subset] = ans;
    
}

int main() {
    
    int n;
    cin >> n;
    matrix.resize(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    int bitmask = (1<<n) - 1; // another way to write 2^n - 1
    // this will represent set of jobs that are remaining to be completed at any moment
    
    dp.resize(n+1, vector<int>(bitmask + 1, -1));
    // dp[i][mask] = minimum cost if we are at current worker and mask 
    
    int ans = fun(1, bitmask, n);
    cout << ans;
    
    return 0;
}
