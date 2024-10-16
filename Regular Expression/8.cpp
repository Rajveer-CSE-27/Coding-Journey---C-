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
  
  string s = "a as ape bug aefkn";
  
  // get all strings that start with 'a' has second character in a-z and length can be anyting.
  regex rgx("a[a-z]+"); 
  
  // + means it will take all the characters untill a space.
  
  printAllMatches(s, rgx);
  
  return 0;
}
