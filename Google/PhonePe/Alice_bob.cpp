#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**
Approach :: 
  
  3 cases possible :: 
      1. Left person starts to walk towards right and right person starts to walk towards left
         And both reach end
      
      2. Left person starts to walk towards left and right person starts to walk towards right
         And both reach end. And then start from their respective ends to finish the middle portion
         
      3. Both start to finish middle portion first. And then turn back towards their end.
**/

  
int main() {
  
  int n, x, y;
  cin >> n >> x >> y;
  
  int left = min(x,y), right = max(x,y);
  
  // Case 1 :: 
  
  int d1 = n - left;
  if(right == n) {
    d1--;
  }
  
  int d2 = right - 1;
  if(left == 1) {
    d2--;
  }
  
  int ans1 = max(d1, d2);
  
  // Case 2 :: 
  
  d1 = left - 1;
  d2 = n - right;
  
  int ans2;
  
  if(left + 1 > right - 1) {
    ans2 = max(d1, d2);
    
  } else {
    int t1 = d1*2, t2 = d2*2;
    ans2 = max(t1,t2);
    
    int tempLeft = left, tempRight = right;
    // tempLeft will tell position of leftElement and similarly tempRight
    
    if(t1 > t2) {
      tempRight -= (t1 - t2);
    } else {
      tempLeft += (t2 - t1);
    }
    
    if(tempLeft < tempRight) {
      int diff = tempRight - tempLeft;
      
      ans2 += diff/2;
    }
    
  }
  
  
  
  // Case 3 :: 
  
  int ans3 = INT_MAX;
  
  for(int i=left; i <= right; i++) {
    // left wala will cover till i
    
    d1 = i - left;
    d2 = right - (i+1);
    
    
    if(left != 1) {
      d1 += i - 1;
    }
    
    
    if(right != n) {
      d2 += (n - (i+1));
    }
    
    ans3 = min(ans3, max(d1,d2));
    
  }
  
  
  cout << min({ans1, ans2, ans3});
  
  return 0;
  
}
