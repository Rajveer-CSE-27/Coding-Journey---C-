#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

/**

https://www.geeksforgeeks.org/count-of-numbers-in-range-l-r-which-can-be-represented-as-sum-of-two-perfect-powers/

approach :: 
  count all possible numbers from 0 to r which are a valid power of a valid number
  eg :: if r = 25 then :: {0,1,4,8,9,16,25}
  because p,q > 1 and a,b >= 0
  
  then find all the pairs in this values such that sum >= l and <= r
**/

signed main() {
  
  
  int l,r;
  cin >> l >> r;
  
  vector<int> vc;
  vc.push_back(0);
  vc.push_back(1);
  
  for(int i=2; i<=sqrt(r); i++) {
    
    int val = i*i;
    while(val <= r) {
      vc.push_back(val);
      val *= i;
    }
    
  }
  
  set<int> st;
  
  for(int i=0; i<vc.size(); i++) {
    for(int j=i; j<vc.size(); j++) {
      
      int temp = vc[i] + vc[j];
      if(temp >= l and temp <= r) {
        st.insert(temp);
      }
      
    }
  }
  
  
  if(!st.empty()) {
    cout << st.size();
  } else {
    cout << 0;
  }
    
  return 0;
}
