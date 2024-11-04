#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int N = 1000001;

/**
https://leetcode.com/discuss/interview-question/3169340/Citadel-Internship-Sumer-2023-or-OA-or-%22Do-they-belong%22


**/

pair<int,int> a,b,c,p,q;

double dist(pair<int,int> a, pair<int,int> b) {
  
  double d1 = (a.first - b.first)*(a.first - b.first);
  double d2 = (a.second - b.second)*(a.second - b.second);
  
  double ans = sqrt(d1 + d2);
  return ans;
  
}

int orientation(pair<int,int> a, pair<int,int> b, pair<int,int> c) {
  // a->b and b->c ka slope
  
  int val = (c.second - b.second)*(b.first - a.first);
  int val2 = (b.second - a.second)*(c.first - b.first);
  
  if(val > val2) {
    return 1; // anticlockwise
  }
  if(val < val2) {
    return 2; // clockwise
  }
  return 0;
  
}

int solve() {

  // checking if triangle is degenerate or not
  double ab = dist(a,b);
  double bc = dist(b,c);
  double ac = dist(a,c);
  
  if(ab + bc <= ac) {
    return 0;
  }
  if(ab + ac <= bc) {
    return 0;
  }
  if(ac + bc <= ab) {
    return 0;
  }
  
  
  
  bool pBelongs = true, qBelongs = true;
  
  int o1 = orientation(a,p,b);
  int o2 = orientation(a,p,c);
  
  if(o1 != 0 and o2 != 0 and o1 == o2) {
    pBelongs = false;
  }
  
  o1 = orientation(b,p,a);
  o2 = orientation(b,p,c);
  if(o1 != 0 and o2 != 0 and o1 == o2) {
    pBelongs = false;
  }
  
  
  o1 = orientation(c,p,a);
  o2 = orientation(c,p,b);
  if(o1 != 0 and o2 != 0 and o1 == o2) {
    pBelongs = false;
  }
  
  o1 = orientation(a,q,b);
  o2 = orientation(a,q,c);
  
  if(o1 != 0 and o2 != 0 and o1 == o2) {
    qBelongs = false;
  }
  
  o1 = orientation(b,q,a);
  o2 = orientation(b,q,c);
  if(o1 != 0 and o2 != 0 and o1 == o2) {
    qBelongs = false;
  }
  
  
  o1 = orientation(c,q,a);
  o2 = orientation(c,q,b);
  if(o1 != 0 and o2 != 0 and o1 == o2) {
    qBelongs = false;
  }
  
  if(qBelongs == true and pBelongs == true) {
    return 3;
  }
  if(qBelongs == false and pBelongs == false) {
    return 4;
  }
  if(qBelongs == true) {
    2;
  }
  return 1;

}

int main() {
  
  
  
  cin >> a.first >> a.second;
  cin >> b.first >> b.second;
  cin >> c.first >> c.second;
  cin >> p.first >> p.second;
  cin >> q.first >> q.second;
  
  
  cout << solve();
  
  
    
  return 0;
  
  
  
  
}
