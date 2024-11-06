#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;


int main() {
    
  int n;
  cin >> n;
  vector<vector<string>> vc(n, vector<string>(2));
  for(int i=0; i<n; i++) {
    cin >> vc[i][0] >> vc[i][1];
  }
  
  stack<char> left, right;
  
  for(int i=0; i<n; i++) {
    
    if(vc[i][0] == "Insert") {
      
      
      for(char c:vc[i][1]) {
        left.push(c);
      }
      
    } else if(vc[i][0] == "Left") {
      
      int x = stoi(vc[i][1]);
      
      while(!left.empty() and x > 0) {
        
        char c = left.top();
        left.pop();
        right.push(c);
        x--;
        
      }
      
    } else if(vc[i][0] == "Right") {
      
      int x = stoi(vc[i][1]);
      
      while(!right.empty() and x > 0) {
        
        char c = right.top();
        right.pop();
        left.push(c);
        x--;
        
      }
      
    } else if(vc[i][0] == "Backspace") {
      
      int x = stoi(vc[i][1]);
      
      while(!left.empty() and x > 0) {
        left.pop();
        x--;
      }
      
    } else if(vc[i][0] == "Delete") {
      
      int x = stoi(vc[i][1]);
      
      while(!right.empty() and x > 0) {
        right.pop();
        x--;
      }
      
    } else {
      
      int x = stoi(vc[i][1]);
      
      string ans;
      int l = x + 1; // print x+1 characters from left becase cursor at top of left
      
      while(!left.empty() and l > 0) {
        char c = left.top();
        ans += c;
        left.pop();
        l--;
      }
      
      reverse(ans.begin(), ans.end());
      for(int i=0; i<ans.length(); i++) {
        left.push(ans[i]);
      }
      
      int r = x; // print x characters in right
      string temp;
      
      while(!right.empty() and r > 0) {
        char c = right.top();
        temp += c;
        right.pop();
        r--;
      }
      
      ans += temp;
      
      reverse(temp.begin(), temp.end());
      
      for(int i=0; i<temp.length(); i++) {
        right.push(temp[i]);
      }
      
      
      cout << ans << '\n';
    }
    
  }
  
  return 0;  
}
