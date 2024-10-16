#include <bits/stdc++.h>
#include <regex>
using namespace std;


/**
https://www.youtube.com/watch?v=NPccLyAHD6Y


**/

void printAllMatches(string s, regex rgx) {
  
  sregex_iterator it(s.begin(), s.end(), rgx);
  sregex_iterator last;
  
  while(it != last) {
    
    smatch curr = *it;
    cout << curr.str() << '\n';
    it++;
  }
  cout << '\n';
}

int main() {
  
  
  string s = "206-709-3100 202-456-1111 212-832-2000";
  // get all the numbers individually
  
  regex rgx(".{3}-.{3}-.{4}");
  printAllMatches(s, rgx);
  
  
  return 0;
}
