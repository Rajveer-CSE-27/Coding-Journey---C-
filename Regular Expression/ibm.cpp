#include <bits/stdc++.h>
#include <regex>
using namespace std;


/**
https://www.youtube.com/watch?v=NPccLyAHD6Y


**/

void printAllMatches(string s, regex rgx) {
  
  sregex_iterator it(s.begin(), s.end(), rgx); // iterator of valid matches of rgx in s
  // currently it is pointing to first location of match
  
  
  sregex_iterator last; // end location of above defined matches
  
  while(it != last) {
    
    smatch curr = *it; // smatch is an instantiation of the match_results
    cout << curr.str() << '\n';
    
    it++;
  }
  
  // other functions of smatch are str(), position(), and length()
  // curr.length() will give length of current matching
  // curr.position() will give 0 based position of current matching in original string
  
}

int main() {
  
  
  string s;
  
  regex rgx("[a-z]{1,6}_?\\d{0,4}@hackerrank\\.com");
  printAllMatches(s, rgx);
  
  return 0;
}
