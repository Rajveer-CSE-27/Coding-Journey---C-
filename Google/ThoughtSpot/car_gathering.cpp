#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

/**

https://www.chegg.com/homework-help/questions-and-answers/n-cars-parked-random-spot-city-want-move-cars-several-times-park-city-square-cars-move-lef-q206953615

approach :: 
  calculate total distance that needs to be travelled by each car
  If all even or all odd then there will be an answer else -1 {because ek ko agar even length travel karna hai and ek ko odd to that is impossible in given scenario}
  
  now with binary search on answer get the value whose x whose sum (1 + 2 + .. + x) will be greater than or equal to the greatest diff and also
        difference of (sm of (1,,....x) - greatest val) must be even
        

**/

signed main() {
  
  int n,m;
  cin >> n >> m;
  // 2*m is the maximum x distance and 2*m is maximum y distance
  // hence total maximum distance that one can travel is 4*m
  
  pair<int,int> centre;
  cin >> centre.first >> centre.second;
  vector<pair<int,int>> vc(n);
  for(int i=0; i<n; i++) {
    cin >> vc[i].first >> vc[i].second;
  }
  
  bool odd = false, even = false;
  int mx = -1;
  for(int i=0; i<n; i++) {
    int v1 = abs(vc[i].first - centre.first);
    int v2 = abs(vc[i].second - centre.second);
    
    int tot = v1 + v2;
    if(tot%2 == 0) {
      even = true;
    } else {
      odd = true;
    }
    mx = max(mx, tot);
  }
  
  
  if(odd == true and even == true) {
    cout << -1;
    return 0;
  }
  
  int low = 0; // obvious bad
  int high = 5*m; // obvious good
  int ans = high;
  
  while(low <= high) {
    int mid = (low + high)/2;
      
    int temp = (mid * (mid + 1))/2;
    if(temp < mx) {
      low = mid + 1;
        
    } else {
        
      int diff = temp - mx;
      if(diff%2 == 0) {
        ans = mid;
        high = mid - 1;
      } else {
        // find the next greater element whose sum - diff is even
        
        if(mx%2 == 0) {
          
          // then we need to find (x > mid) such that (x*(x+1))/2 is even
          // either x or (x+1) must be multiple of 4
          
          for(int j=1; j<4; j++) {
            int x = mid + j;
            if((x%4 == 0) or ((x+1)%4 == 0)) {
              ans = x;
              break;
            }
          }
          
        } else {
          
          // then we need to find (x > mid) such that (x*(x+1))/2 is odd
          // either x or (x+1) must not be multiple of 4
          
          for(int j=1; j<4; j++) {
            int x = mid + j;
            if((x%4 != 0) and ((x+1)%4 != 0)) {
              ans = x;
              break;
            }
          }
          
        }
        
        
        high = mid - 1;
      }
           
    }
      
  }
  
  cout << ans;
  
  return 0;
}
