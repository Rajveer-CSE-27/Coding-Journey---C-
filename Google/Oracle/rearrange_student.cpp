#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int N = 1000001;

/**
https://leetcode.com/discuss/interview-question/5591683/OA-question/

**/



int main() {
  
  int n;
  cin >> n;
  vector<int> boys(n), girls(n);
  for(int i=0; i<n; i++) {
    cin >> boys[i];
  }
  for(int i=0; i<n; i++) {
    cin >> girls[i];
  }
  
  map<int,int> mp;
  for(int i=0; i<n; i++) {
    mp[boys[i]]++;
    mp[girls[i]]--;
  }
  
  
  vector<int> vc1;
  
  for(auto it:mp) {
    int key = it.first;
    int val = it.second;
    
    if(abs(val)%2 == 1) {
      cout << -1;
      return 0;
    }
    
    int v = abs(val);
    v /= 2;
    while(v--) {
      vc1.push_back(key);
    }
    
  }
  
  sort(vc1.begin(), vc1.end());
  
  int ans = 0;
  int m = vc1.size()/2;
  
  for(int i=0; i<m; i++) {
    ans += vc1[i];
  }
    
    
  cout << ans;
  
  
  return 0;
  
  
  
}
