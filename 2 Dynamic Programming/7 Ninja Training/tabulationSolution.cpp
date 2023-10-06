/**
Problem Statement : A Ninja has an ‘N’ Day training schedule. 
                    He has to perform one of these three activities (Running, Fighting Practice, or Learning New Moves) each day. 
                    There are merit points associated with performing an activity each day. 
                    The same activity can’t be performed on two consecutive days. 
                    We need to find the maximum merit points the ninja can attain in N Days.
                    We are given a 2D Array POINTS of size ‘N*3’ which tells us the merit point of specific activity on that particular day. 
                    Our task is to calculate the maximum number of merit points that the ninja can earn.
                    
Approach : We will apply tabulation i.e bottom-up DP over the memoization solution to save space

Time Complexity = nearly O(n*3*3) = O(n) because there are N*3 states and for every state, we are running a for loop iterating three times
Space Complexity = O(n*3) for dp matrix.

**/
#include <bits/stdc++.h>
using namespace std;

// we will consider that on each day ninja can perform either 0,1,2 activity. We will assign 3 for no activity to signify the day before the training starts.
// to compute data for ith day we would need which activity it performed on i+1th day and points till that day because we are performing top-down approach.


int main() {
    
    int n; // number of days
    cin >> n;
    vector<vector<int>> points(n, vector<int>(3));
    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            cin >> points[i][j];
        }
    }
    
    
    vector<vector<int>> dp(n, vector<int>(3, 0));
    // dp[i][j] will give the maximum number of points that can be scored on ith day given task j was performed on prev day.
    
    
    // thoda sa change karna hai bass. Samaj jaoge
    for(int j=0; j<3; j++) {
        dp[n-1][j] = points[n-1][j];
    }
    
    
    for(int i=n-2; i>=0; i--) {
        for(int j=0; j<3; j++) {
            
            int tempPoints = 0;
            for(int k=0; k<3; k++) {
                if(k != j) {
                    tempPoints = max(tempPoints, dp[i+1][k]);
                }
            }
            dp[i][j] = points[i][j] + tempPoints;
        }
    }
    
    
    int ans = -1;
    for(int i=0; i<3; i++) {
        ans = max(ans, dp[0][i]);
    }
    
    cout << ans << '\n';
    return 0;
}
