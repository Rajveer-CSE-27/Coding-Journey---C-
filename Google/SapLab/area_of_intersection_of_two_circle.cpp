#include <bits/stdc++.h>
using namespace std;
#define ll long long

const double pi = 3.1415;

/**
https://www.geeksforgeeks.org/area-of-intersection-of-two-circles/
**/
 
int main() {
  
  
  int x1,y1,r1,x2,y2,r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  
  double d, alpha, beta, a1, a2;
  
  double ans;
  
  double X1 = (double)x1; 
  double X2 = (double)x2; 
  double Y1 = (double)y1; 
  double Y2 = (double)y2; 
  double R1 = (double)r1; 
  double R2 = (double)r2;  
  
  
  // eucledian distance between 2 centres
  d = sqrt((X2 - X1)*(X2 - X1) + (Y2 - Y1)*(Y2 - Y1));
  
  
  if(d > R1 + R2) {
    // never intersect
    ans = 0;
    
  } else if(d <= (R1 - R2) and R1 >= R2) {
    
    // circle 2 inside circle 1
    ans = pi*R2*R2;
  } else if(d <= (R2 - R1) and R2 >= R1) {
    
    // circle 1 inside circle 2
    ans = pi*R1*R1;
    
  } else {
    
    alpha = acos((R1*R1 + d*d - R2*R2) / (2 * R1 * d)) * 2;
    beta = acos((R2*R2 + d*d - R1*R1) / (2 * R2 * d)) * 2;
    
    a1 = 0.5 * alpha * R1 * R1 - 0.5 * R1 * R1 * sin(alpha);
    a2 = 0.5 * beta * R2 * R2 - 0.5 * R2 * R2 * sin(beta);
    
    ans = a1 + a2;
    
  }
  
  cout << fixed << setprecision(10) << ans;
  
  
  return 0;
}
