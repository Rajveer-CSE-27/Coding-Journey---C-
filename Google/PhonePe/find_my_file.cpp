#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**

**/

bool comp(deque<int>& dq, vector<int>& b, int& m) {
  
  int i=0;
  bool flag = true;
  
  for(auto it = dq.cbegin(); it != dq.cend(); it++) {
    
    if((*it) != b[i]) {
      if(flag == true) {
        flag = false;
      } else {
        return false;
      }
    }
    i++;
    
    
  }
  
  return true;
}
  
int main() {
  
  
  int n,m;
  cin >> n >> m;
  
  vector<int> a(n), b(m);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  for(int j=0; j<m; j++) {
    cin >> b[j];
  }
  
  
  // Brute force
  deque<int> dq;
  
  for(int i=0; i<m; i++) {
    dq.push_back(a[i]);
  }
  
  vector<int> ans;
  if(comp(dq, b, m) == true) {
    ans.push_back(1);
  }
  
  for(int i=m; i<n; i++) {
    dq.pop_front();
    dq.push_back(a[i]);
    
    if(comp(dq, b, m) == true) {
      ans.push_back(i - m + 1);
    }
  }
  
  cout << ans.size() << '\n';
  for(auto it:ans) {
    cout << it << " ";
  }
 
  
  return 0;
  
}
