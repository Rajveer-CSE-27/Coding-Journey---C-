#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;


int main() {
  
  int k;
  cin >> k;
  
    
  string s;
  cin >> s;
  
  int n = s.length();
  
  
  int level = -1;
  int num = 0;
  bool flag = false; // for handling negative values
  
  map<int,int> mp;
  
  
  for(int i=0; i<n; i++) {
    if(s[i] == '(') {
      
      if(flag == true) {
        num *= -1;
        flag = false;
      }
      
      mp[level] += num;
      num = 0;
      
      
      level++;
    } else if(s[i] == ')') {
      
      if(flag == true) {
        num *= -1;
        flag = false;
      }
      
      mp[level] += num;
      num = 0;
      
      level--;
    } else if(s[i] == '-') {
      
      flag = true;
      
    } else {
      num *= 10;
      num += (s[i] - '0');
    }
  }
  
  cout << mp[k];
  
  return 0;
}
