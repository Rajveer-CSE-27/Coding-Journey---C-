#include <bits/stdc++.h>
#include <regex>
using namespace std;


/**
https://www.youtube.com/watch?v=9K4N6MO_R1Y&t=7s
**/

void printAllMatches(string s, regex rgx) {
  
  
  sregex_iterator it(s.begin(), s.end(), rgx);
  sregex_iterator last;
  
  while(it != last) {
    smatch curr = *it;
    
    cout << curr.str() << '\n';
    
    it++;
  }
  
}

int main() {
  
  /**
  
  --> Problem 
  
    Create a regex that matches email addresses from a string
    
    1 to 20 lowercase and uppercase letters, numbers, also ._%+-
    An @ symbol
    2 to 20 lowercase and uppercase letters, numbers, also ._-
    A period i.e .
    2 to 3 lowercase and uppercase letters
  
  **/
  string s = "db@aol.com m@.com @apple.com db@.com";
  
  regex rgx("[\\w.+%-]{1,20}@[\\w.-]{2,20}.[a-zA-Z]{2,3}");
  
  printAllMatches(s, rgx);
  
  return 0;
}
