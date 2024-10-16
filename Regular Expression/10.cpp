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
  
}

int main() {
  
  string s = "cat cats catsi cte";
  
  // print all strings that can be cat or cats
  regex rgx("cats?");
  
  // this means that any string which is cat would be accepted
  // and we check if after cat we have 's'. If yes then it would also be accepted
  
  printAllMatches(s, rgx);
  cout << '\n';
  
  s = "doctor doctors doctor's doctos sorewr doctoring";
  
  // print all the strings that have doctor as prefix
  
  regex rgx2("doctor[\\w]*");
  
  // this means that after doctor we can have any combination of valid letters except space
  // []+ signifies any combination of What's inside bracket of size >= 1
  // []* signifies any combination of What's inside bracket of size >= 0
  
  rgx2 = ("doctor[\\w]+");
  
  // if we also want to include '
  rgx2 = ("doctor[\\w']*");
  
  printAllMatches(s, rgx2);
  cout << '\n';
  
  
  return 0;
}
