#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int N = 1000001;

/**
map se ho jaega

**/


int main() {
  
  int n;
  cin >> n;
  vector<int> vc(n);
  for(int i=0; i<n; i++) {
    cin >> vc[i];
  }
  
  int talentCnt;
  cin >> talentCnt;
  
  
  vector<int> ans(n);
  map<int,int> mp;
   
  int j = n-1;
  
  for(int i=n-1; i>=0; i--) {
    
    mp[vc[i]]++;
    
    while(j > i) {
      mp[vc[j]]--;
      if(mp[vc[j]] == 0) {
        mp.erase(vc[j]);
      }
      if(mp.size() < talentCnt) {
        mp[vc[j]]++;
        break;
      }
      j--;
    }
    
    if(mp.size() < talentCnt) {
      ans[i] = -1;
    } else {
      
      int cnt = j - i + 1;
      ans[i] = cnt;
    }
    
  }
  
  for(auto x:ans) {
    cout << x << " ";
  }
    
  return 0;
  
  
  
  
}
