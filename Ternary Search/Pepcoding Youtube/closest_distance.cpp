#include <bits/stdc++.h>
using namespace std;

/**
    Problem link :: https://lightoj.com/problem/closest-distance
    
    Approach :: 
        We observe that the ratio of distance that 1st person moves is always same as ratio of distance 2nd person moves.
        That is if 1st person moves 10% of its total distance then 2nd person also moves 10% of his total distance.
        
        Now as we move from ratio 0 to 1 then we see unimodal function. That is first the closest distance decreases then increases.
        Hence apply ternary search.

**/

double distance(double x1, double y1, double x2, double y2) {
    
    double ans = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1-y2));
    return ans;
}


void solve() {
    double ax, ay, bx, by, cx, cy, dx, dy;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    
    while(distance(ax,ay,bx,by) > 1e-11) {
        double am1_x = ax + (bx - ax)/3, am1_y = ay + (by - ay)/3;
        double am2_x = bx - (bx - ax)/3, am2_y = by - (by - ay)/3;
        
        double cm1_x = cx + (dx - cx)/3, cm1_y = cy + (dy - cy)/3;
        double cm2_x = dx - (dx - cx)/3, cm2_y = dy - (dy - cy)/3;
        
        double dm1 = distance(am1_x, am1_y, cm1_x, cm1_y);
        double dm2 = distance(am2_x, am2_y, cm2_x, cm2_y);
        
        if(dm1 > dm2) {
            ax = am1_x;
            ay = am1_y;
            cx = cm1_x;
            cy = cm1_y;
        } else if(dm1 < dm2) {
            bx = am2_x;
            by = am2_y;
            dx = cm2_x;
            dy = cm2_y;
        } else {
            ax = am1_x;
            ay = am1_y;
            cx = cm1_x;
            cy = cm1_y;
            bx = am2_x;
            by = am2_y;
            dx = cm2_x;
            dy = cm2_y; 
        }
    }
    
    double ans = distance(ax, ay, cx, cy);
    
    if(ans - (int)ans > 0.000001) { // for this particular question.
        cout << setprecision(15) << ans;
        return;
    }
    
    cout << (int)ans;
    
    
   
}

int main() {
    
    int t;
    cin >> t;
    int caseNumber = 1;
    
    while(t--) {
        cout << "Case " << caseNumber << ": ";
        solve();
        cout << '\n';
        caseNumber++;
    }
    
    return 0;
}
