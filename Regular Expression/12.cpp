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
  
  
  // word boundaries
  
  string s = "ape at the apex";
  
  regex rgx("ape");
  printAllMatches(s,rgx);
  // hume sirf wahi word chahiye jo ape hai but yaha apex ka ape bhi aa raha hai OUTPUT me.
  
  // if we want only strings that are ape then we need to define word boundary.
  rgx = ("\\bape\\b");
  // \\b and \\b ke beech me jo bhi hoga bass agar apna word exactly usme lie karega to hi match hoga.
  // This is called word boundary.
  
  printAllMatches(s, rgx);
  
  
  
  // string boundaries
  
  s = "get this bastard @";
  // get all the strings until we get @
  
  rgx = ("^.*[^@]");
  // ^ marks start of string boundary of original string. This tells that start string from first location in input string
  // .*[^@] means include anything until we get @.
  
  // if there are multiple @ it will get the string till before last @.
  
  printAllMatches(s, rgx);
  
  s = "@ now get this";
  // get all the strings after @
  
  rgx = ("[^@\\s].*$");
  
  // $ means get everything till end of original string
  
  printAllMatches(s, rgx);
  
  
  return 0;
}
