#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int N = 1000001;

/**
https://thejoboverflow.com/p/p1519/

sort karke ho jaega
**/


int main() {
  
  int n;
  cin >> n;
  
  vector<pair<ll, short>> vc;
  for(int i=0; i<n; i++) {
    ll start, life;
    cin >> start >> life;
    
    vc.push_back({start, 1});
    ll die = start + life + 1ll;
    vc.push_back({die, -1});
    
  }
  
  n *= 2; // very important step
  
  int q;
  cin >> q;
  vector<pair<ll,int>> query(q); 
  for(int i=0; i<q; i++) {
    cin >> query[i].first;
    query[i].second = i;
  }
  
  sort(vc.begin(), vc.end());
  sort(query.begin(), query.end());
  
  vector<int> ans(q);
  
  int i=0, j=0, cnt = 0;
  
  while(j < q) {
    
    while(i < n and vc[i].first <= query[j].first) {
      cnt += vc[i].second;
      i++;
    }
    
    ans[query[j].second] = cnt;
    j++;
  }
  
  
  for(auto it:ans) {
    cout << it << " ";
  }
  
  
  return 0;  
}
