/**
Problem Statement : A Ninja has an ‘N’ Day training schedule. 
                    He has to perform one of these three activities (Running, Fighting Practice, or Learning New Moves) each day. 
                    There are merit points associated with performing an activity each day. 
                    The same activity can’t be performed on two consecutive days. 
                    We need to find the maximum merit points the ninja can attain in N Days.
                    We are given a 2D Array POINTS of size ‘N*3’ which tells us the merit point of specific activity on that particular day. 
                    Our task is to calculate the maximum number of merit points that the ninja can earn.
                    
Approach :we will apply more space optimization because we only need previous state at each time.

Time Complexity = nearly O(n*3*3) = O(n) because there are N*3 states and for every state, we are running a for loop iterating three times
Space Complexity = O(1).

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
        
    vector<int> task(3);
    for(int i=0; i<3; i++) {
        task[i] = points[n-1][i];
    }    
    
    for(int i=n-2; i>=0; i--) {
        vector<int> tempTask(3); // very important step nahi to updated value use karte rahoge
        for(int j=0; j<3; j++) {
            
            int tempPoints = 0;
            for(int k=0; k<3; k++) {
                if(k != j) {
                    tempPoints = max(tempPoints, task[k]);
                }
            }
            tempTask[j] = points[i][j] + tempPoints;
        }
        task = tempTask;
    }
    
    
    int ans = 0;
    for(int i=0; i<3; i++) {
        ans = max(ans, task[i]);
    }
    
    cout << ans << '\n';
    return 0;
}
