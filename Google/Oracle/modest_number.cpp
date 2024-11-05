#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;


/**
https://studyx.ai/homework/101512363-1-modest-numbers-write-a-program-that-identifies-modest-numbers-lying-in-all-a-given


 A modest number is defined as a number that can be split into two parts,
left and right, such that the remainder of the number when divided by the right part equals the left part.
 To determine if a number is modest, one must check all possible partitions of the number and verify if the condition holds true for at least one partition.
 
Given range l,r find all modest numbers in the range

100 <= l <= 1e5
101 <= r <= 1e5

**/

bool check(int x) {
  
  
  int d = 10;
  
  while(x/d > 0) {
    
    int right = x%d;
    int left = x/d;
    
    
    d *= 10;
    
    if(right == 0) {
      continue;
    }
    int rem = x%right;
    
    if(rem == left) {
      return true;
    }
    
    
  }
  
  return false;
  
}

int main() {
  
  int l,r;
  cin >> l >> r;
  
  vector<int> ans;
  
  for(int i=l; i<=r; i++) {
    if(check(i) == true) {
      ans.push_back(i);
    }
  }
  
  if(ans.empty()) {
    cout << "No modest numbers";
  } else {
    for(auto it:ans) {
      cout << it << " ";
    }
  }
  
  return 0;  
}
