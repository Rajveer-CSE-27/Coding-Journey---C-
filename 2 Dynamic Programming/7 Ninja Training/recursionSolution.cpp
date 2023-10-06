/**
Problem Statement : A Ninja has an ‘N’ Day training schedule. 
                    He has to perform one of these three activities (Running, Fighting Practice, or Learning New Moves) each day. 
                    There are merit points associated with performing an activity each day. 
                    The same activity can’t be performed on two consecutive days. 
                    We need to find the maximum merit points the ninja can attain in N Days.
                    We are given a 2D Array POINTS of size ‘N*3’ which tells us the merit point of specific activity on that particular day. 
                    Our task is to calculate the maximum number of merit points that the ninja can earn.
                    
Approach : First thing comes to mind is that we use recursion and identify all the possible paths in the grid
           that Ninja could take and get the maximum points of path out of all paths.
           Use bottom - up approach and each time handle the case that each time we cannot perform an activity that was performed last time.

Time Complexity = nearly O(2^n) because for each index(or day) we will be exploring 2 paths(i.e could perform any of the 2 activities that was not performed last time
                    except the first day where he can perform any of the 3).
Space Complexity = O(n) : auxillary stack space. Because he can perform only 1 activity per day.

**/
#include <bits/stdc++.h>
using namespace std;

// we will consider that on each day ninja can perform either 0,1,2 activity. We will assign 3 for no activity to signify the day before the training starts.
// to compute data for ith day we would need which activity it performed on i+1th day and points till that day because we are performing top-down approach.

int ninjaTraining(int i, vector<vector<int>>& points, int last) {
    if(i == 0) { // base case
        int maxi = -1;
        for(int j=0; j<4; j++) {
            if(j != last) {
                maxi = max(maxi, points[0][j]);
            }
        }
        return maxi;
    }
    
    int maxi = -1;
    for(int j=0; j<4; j++) {
        if(j != last) {
            int tempPoints = points[i][j] + ninjaTraining(i-1, points, j);
            maxi = max(maxi, tempPoints);
        }
    }
    return maxi;
}

int main() {
    
    vector<vector<int>> points = {{18,11,19},{4,13,7},{1,8,13}};
    
    int n = points.size(); // number of days
    int ans = ninjaTraining(n-1, points, 3);
    
    cout << ans << '\n';
    return 0;
}
