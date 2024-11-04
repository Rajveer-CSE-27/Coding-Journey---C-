#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int N = 1000001;

/**
binary search on answer
**/

bool check(int x, int& n, vector<int>& vc, int& k) {
  // counting number of clusters if atmost x distance allowed
  
  int cnt = 0;
  int last = 0;
  
  for(int i=0; i<n; i++) {
    if(vc[i] > last) {
      
      cnt++;
      last = vc[i] + 2*x;
      
    }
  }
  
  return (cnt <= k);
  
  
}

int main() {
  
  int n;
  cin >> n;
  vector<int> vc(n);
  for(int i=0; i<n; i++) {
    cin >> vc[i];
  }
  int k;
  cin >> k;
  
  sort(vc.begin(), vc.end());
  
  
  if(k >= n) {
    cout << 0;
    return 0;
  }
  
  int low = 0; // obvious bad
  int high = vc[n-1] - vc[0] + 1; // obvious good
  int ans = high;
  
  while(low <= high) {
    int mid = (low + high)/2;
    
    if(check(mid, n, vc, k) == true) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
    
  }
  
  cout << ans;
  
  
  return 0;  
}
