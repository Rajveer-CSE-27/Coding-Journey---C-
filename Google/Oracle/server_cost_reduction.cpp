#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int N = 1000001;

/**
server cost reduction
greedy
**/


int main() {
  
  int n;
  cin >> n;
  vector<int> vc(n);
  for(int i=0; i<n; i++) {
    cin >> vc[i];
  }
  int load;
  cin >> load;
  
  
  map<int,int> mp;
  for(int i=0; i<n; i++) {
    mp[vc[i]]++;
  }
  
  auto it = mp.end();
  it--;
  
  int cnt = 0;
  
  while(it != mp.begin()) {
    
    int key = it->first;
    int val = it->second;
    
    if(key <= load) {
      int d = load/key;
      d = min(d, val);
      
      cnt += d;
      load -= d*key;
    }
    
    it--;
    
  }
  
  
  int key = it->first;
  int val = it->second;
    
  if(key <= load) {
    int d = load/key;
    d = min(d, val);
      
    cnt += d;
    load -= d*key;
  }
  
  if(load == 0) {
    cout << cnt;
  } else {
    cout << -1;
    
  }
    
    
  return 0;
}
