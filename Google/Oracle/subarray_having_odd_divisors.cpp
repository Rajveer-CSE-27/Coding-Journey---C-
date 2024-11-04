#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int N = 1000001;

/**
Subarray having odd no of divisors :
This code aims to count the number of subarrays in a given array arr such that the product of elements in each subarray has an odd number of divisors.
**/

bool check(int x) {
  
  // checking whether x is perfect square or not
  int t = sqrt(x);
  
  if(t*t == x) {
    return true;
  }  
  return false;
}

int main() {
  
  int n;
  cin >> n;
  vector<int> vc(n);
  for(int i=0; i<n; i++) {
    cin >> vc[i];
  }
  
  long long prefProduct = 1;
  map<long long,int> mp;
  mp[1] = 1; // to handle base case of perfect square
  
  int cnt = 0;
  
  for(int i=0; i<n; i++) {
    prefProduct *= vc[i];
    
    for(auto it:mp) {
      
      int key = it.first;
      int val = it.second;
      
      if(check(prefProduct/key) == true) {
        cnt += val;
      }
      
    }
    
    mp[prefProduct]++;
    
  }
  
  cout << cnt;
    
    
  return 0;
}
