#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**
 find largest prime factor of number 
 
**/

ll maxPrimeFactors(ll n) {
  
  ll ans = -1;
  while(n%2 == 0) {
    ans = 2;
    n /= 2;
  }
  
  for(int i=3; i<sqrt(n); i+=2) {
    
    while(n%i == 0) {
      ans = i;
      n /= i;
    }
    
  }
  
  if(n > 2) {
    ans = n;
  }
  
  return n;
  
}

  
int main() {
  
  ll n = 15; 
  cout << maxPrimeFactors(n) << '\n'; 

  n = 25698751364526; 
  cout << maxPrimeFactors(n); 
  
  return 0;
  
}
