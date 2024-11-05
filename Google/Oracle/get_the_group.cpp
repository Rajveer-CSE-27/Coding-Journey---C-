#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;


/**
dsu
https://leetcode.com/discuss/interview-question/5867288/Oracle-or-OA-or-Get-The-Groups/
**/


template<class T>
class unionSet {
  
  unordered_map<T,T> parent;
  unordered_map<T, pair<int,int>> representative_info; // size, height
  
public:
  
  void makeSet(T x) {
    parent[x] = x;
    representative_info[x] = {1,0};
  }
  
  T find(T x) {
    
    if(parent[x] == x) {
      return x;
    }
    return parent[x] = find(parent[x]);
    
  }
  
  void unionDo(T v, T u) {
    
    T rv = find(v);
    T ru = find(u);
    
    if(rv ==  ru) {
      return;
    }
    
    int hv = representative_info[rv].second;
    int hu = representative_info[ru].second;
    
    if(hv > hu) {
      
      parent[ru] = rv;
      representative_info[rv].first += representative_info[ru].first;
      representative_info.erase(ru);
      
    } else {
      
      parent[rv] = ru;
      representative_info[ru].first += representative_info[rv].first;
      if(hv == hu) {
        representative_info[ru].second++;
      }
      
      representative_info.erase(rv);
    }
    
  }
  
  int components() {
    return representative_info.size();
  }
  
};


int main() {
  
  unionSet<int> dsu;
  
  int n,m;
  cin >> n >> m;
  
  vector<string> query(m);
  vector<int> vc1(m), vc2(m);
  
  for(int i=0; i<m; i++) {
    cin >> query[i];
  }
  for(int i=0; i<m; i++) {
    cin >> vc1[i];
  }
  for(int i=0; i<m; i++) {
    cin >> vc2[i];
  }
  
  for(int i=1; i<=n; i++) {
    dsu.makeSet(i);
  }
  
  for(int i=0; i<m; i++) {
    
    if(query[i] == "Friend") {
      dsu.unionDo(vc1[i], vc2[i]);
    } else {
      cout << dsu.components() << " ";
    }
    
  }
  
  return 0;  
}
