#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int N = 1000001;

/**
https://leetcode.com/discuss/interview-question/5403037/Summer-Internship-oror-DE-Shaw-oror-OA-oror-Detail-Guide-for-internships/
Given an array products of size n and an integer k (k>=n) you have select to k products from it and each product you have to select atleast 1.
suppose you select a product t times then discount you will get on this product will be disc=products[i]*pow(2,t-1).
You want maximum discounts by selecting k products from it with atleast 1 product each.
Instead of adding all the discounts from the products you have to take OR operation.


dekho jiski leftmost bit set hai usko hi left shift maaro
**/



signed main() {
  
  int n,k;
  cin >> n >> k;
  vector<int> vc(n);
  for(int i=0; i<n; i++) {
    cin >> vc[i];
  }
  
  k -= n; // handling atleast 1 case
  int msbSet = 0;
  
  for(int i=0; i<n; i++) {
    
    for(int j=0; j<32; j++) {
      
      if((vc[i]&(1<<j)) != 0) {
        msbSet = max(msbSet, j);
      }
    }
    
  }
  
  vector<int> prefOr(n), suffOr(n);
  
  for(int i=0; i<n; i++) {
    
    if(i-1 >= 0) {
      prefOr[i] = (vc[i] | prefOr[i-1]);
    } else {
      prefOr[i] = vc[i];
    }
    
  }
  
  for(int i=n-1; i>=0; i--) {
    
    if(i+1 < n) {
      suffOr[i] = (vc[i] | suffOr[i+1]);
    } else {
      suffOr[i] = vc[i];
    }
  }
  
  
  if(k == 0) {
    cout << prefOr[n-1];
    return 0;
  }
  
  
  int mx = 0;
  
  for(int i=0; i<n; i++) {
    
    if((vc[i]&(1<<msbSet)) != 0) {
      
      cout << vc[i] << " ";
      
      int temp = vc[i] * pow(2,k);
      
      if(i - 1 >= 0) {
        temp = (temp | prefOr[i-1]);
      }
      if(i+1 < n) {
        temp = (temp | suffOr[i+1]);
      }
      
      mx = max(mx, temp);
    }
    
    
  }
  
  cout << '\n';
  cout << mx;
  
    
  return 0;
  
}
