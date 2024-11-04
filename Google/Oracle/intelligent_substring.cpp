#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int N = 1000001;

/**
implementation
**/



int main() {
  
  string s;
  cin >> s;
  int k;
  cin >> k;
  
  string charValue;
  cin >> charValue;
  
  string t;
  for(int i=0; i<s.length(); i++) {
    
    t += charValue[s[i] - 'a'];
    
  }
  
  // toggle
  int m = t.length();
  for(int i=0; i<m; i++) {
    if(t[i] == '0') {
      t[i] = '1';
    } else {
      t[i] = '0';
    }
  }
  
  int mx = 0;
  int i=0;
  
  
  int j = 0;
  int cnt = 0;
  
  while(true) {
    
    while(i < m and cnt <= k) {
      cnt += (t[i] - '0');
      if(cnt > k) {
        break;
      }
      i++;
    }
    
    int num = i - j;
    mx = max(mx, num);
    
    
    if(i == m) {
      break;
    }
    
    while(j <= i and cnt > k) {
      cnt -= (t[j] - '0');
      j++;
      if(cnt == k) {
        i++;
      }
      
    }
    
  }
  
  
  cout << mx;
  
  return 0;  
}
