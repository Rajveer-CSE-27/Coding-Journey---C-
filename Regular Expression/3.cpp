#include <bits/stdc++.h>
#include <regex>
using namespace std;


/**
https://www.youtube.com/watch?v=9K4N6MO_R1Y&t=7s
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
  
  string s = "Cat rat mat fat pat catia at";
  
  regex rgx("([crmfp]at)");
  
  // here we are matching for all the strings that have first letter c or r or m or f or p
  // and next 2 letters a and t respectively.
  // NOTE matches me catia ka sirf cat match hoga and wahi print hoga
  
  regex rgx2("([C-Fc-f]at)");
  // first character in range C to F or in range c to f
  // next 2 characters a and t.
  
  regex rgx3("([^Cr]at)");
  // first character anything except C and r 
  // next 2 characters a and t.
  // NOTE :: here ' 'at would be printed. But if "([^Cr ]at)" then at would not be printed
  
  printAllMatches(s, rgx);
  cout << '\n';
  printAllMatches(s, rgx2);
  cout << '\n';
  printAllMatches(s, rgx3);
  cout << '\n';
  
  return 0;
}
