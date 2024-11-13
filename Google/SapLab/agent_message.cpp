#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

// given two numbers p, q. Find minimum number of bits that must be flipped to convert p to q
// -1e4 <= p,q <= 1e9


int main() {
  
  int p,q;
  cin >> p >> q;
  
  bitset<32> b1(p), b2(q);
  cout << b1 << '\n' << b2 << '\n';
  
  int cnt = 0;
  
  for(int i=0; i<32; i++) {
  	bool a = b1.test(i);
  	bool b = b2.test(i);
  	
  	if(a == true and b == false) {
  		cnt++;
  	}
  	if(a == false and b == true) {
  		cnt++;
  	}
  }
  
  cout << cnt;
  
    
  return 0;
  
}
