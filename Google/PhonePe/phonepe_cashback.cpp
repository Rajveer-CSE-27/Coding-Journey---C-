#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**
https://www.geeksforgeeks.org/maximum-sum-subarray-removing-one-element/
Similar to this problem
**/



  
int main() {
  
  int n;
  cin >> n;
  vector<int> vc(n);
  
  for(int i=0; i<n; i++) {
    cin >> vc[i]; 
  }
  
  vector<int> pref(n), suff(n);
  // pref[i] = max subarray sum till i
  // suff[i] = max subarray sum from i till last
  
  int sm = 0;
  
  for(int i=0; i<n; i++) {
    if(sm + vc[i] < 0) {
      sm = 0;
    } else {
      
      sm += vc[i];
    }
    pref[i] = sm;
  }
  
  sm = 0;
  for(int i=n-1; i>=0; i--) {
    
    if(sm + vc[i] < 0) {
      sm = 0;
    } else {
      
      sm += vc[i];
    }
    suff[i] = sm;
  }
  
  
  int ans = INT_MIN;
  
  for(int i=0; i<n; i++) {
    
    if(vc[i] < 0) {
      // replacing the ith element
      int left = 0, right = 0;
      if(i-1 >= 0) {
        left = pref[i-1];
      } 
      if(i+1 < n) {
        right = suff[i+1];
      }
      
      int temp = left + right;
      ans = max(ans, temp); // as we need to get maximum phonepe profit hence minimum subarray sm
    } else {
      int left = 0, right = 0;
      if(i-1 >= 0) {
        left = pref[i-1];
      } 
      if(i+1 < n) {
        right = suff[i+1];
      }

      int temp = vc[i] + left + right;
      ans = max(ans, temp);
    }
    
  }
  
  
  
  cout << ans;
  
  return 0;
  
  
}
