#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**

Binary search on answer
**/

bool check(int x, int& n, int& k, vector<int>& vc) {
  
  
  // power of each bulb = x
  
  int lastEffect = 0;
  int cnt = 0;
  
  for(int i=0; i<n; i++) {
    if(vc[i] > lastEffect) {
      cnt++;
      
      if(cnt > k) {
        return false;
      }
      lastEffect = vc[i] + 2*x;
    }
  }
  return true;
}

  
int main() {
  
  int n,k;
  cin >> n >> k;
  
  vector<int> vc(n);
  for(int i=0; i<n; i++) {
    cin >> vc[i];
  }
  
  int low = 0; // obvious bad
  int high = vc[n-1] - vc[0]; // obvious good
  
  int ans = high;
  while(low <= high) {
    
    int mid = (low + high)/2;
    if(check(mid, n, k, vc) == true) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
    
  }
  
  cout << ans;
  
  return 0;
  
}
