#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int N = 1000001;

/**
Problem Statement
You are given an integer 
𝑁
N and a target 
𝑇
T.

Goal: You need to insert exactly two different digits into the decimal representation of 
𝑁
N at arbitrary positions (including the start and end of the number) to create a new integer.
The resulting integer must be divisible by 3.
The resulting integer must not start with zero.
Given the target 
𝑇
T:

If 
𝑇
=
0
T=0, return the smallest possible integer that can be obtained by following the above rules.
If 
𝑇
=
1
T=1, return the largest possible integer.
If it's not possible to create a valid integer divisible by 3 under these rules, return -1.

Input Format
An integer 
𝑁
N (1 ≤ 
𝑁
N ≤ 
1
0
9
 ).
An integer 
𝑇
T where 
𝑇
T is either 
0
0 or 
1
1.

Output Format
A single integer representing the smallest or largest possible result as per 
𝑇
T, or -1 if no valid integer can be formed.
Constraints
You are allowed to insert exactly two different digits anywhere in the number.
The modified number must be divisible by 3.
The modified number cannot start with zero.
**/

bool check(string s) {
  int sm = 0;
  for(int i=0; i<s.length(); i++) {
    sm += (s[i] - '0');
  }
  return (sm%3 == 0);
}

int main() {
  
  int n,t;
  cin >> n >> t;
  
  string s = to_string(n);
  vector<ll> vc;
  
  for(char i='0'; i<='9'; i++) {
    for(char j='0'; j<='9'; j++) {
      
      if(i != j) { // because 2 distinct
        
        for(int l=0; l<=s.length(); l++) {
          for(int m=i; m<=s.length(); m++) {
            
            string temp = s;
            temp.insert(temp.begin() + l, i);
            temp.insert(temp.begin() + m + 1, j);
            
            if(temp[0] != '0' and check(temp)) {
              vc.push_back(stoll(temp));
            }
            
          }
        }
        
      }
      
    }
  }
  
  if(!vc.empty()) {
    
    if(t==0) {
      cout << *min_element(vc.begin(), vc.end());
    } else {
      cout << *max_element(vc.begin(), vc.end());
    }
    
  } else {
    cout << -1;
  }
  
    
  return 0;
  
}
