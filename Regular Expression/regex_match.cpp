#include <bits/stdc++.h>
#include <regex>
using namespace std;


/**
https://www.tutorialspoint.com/cpp_standard_library/cpp_regex_match.htm

regex_match :: 
    It returns whether the target sequence matches the regular expression rgx.
    The target sequence is either s or the character sequence between first and last, depending on the version used.
    
    It returns true if rgx is matched against the target sequence. false otherwise.
    
**/


int main() {
  
  
  // EXAMPLE 1........................................................................
  
  
  // this is how you form a regex i.e a pattern with string
  regex rgx("(sub)(.*)");
  
  if(regex_match("suject is deaf", rgx)) { // regex match on input 
    cout << "PRESENT\n";
  } else {
    cout << "NOT PRESENT\n";
  }
  
  if(regex_match("subject is deaf", rgx)) {
    cout << "PRESENT\n";
  } else {
    cout << "NOT PRESENT\n";
  }
  
  
  // EXAMPLE 2........................................................................
  
  string s = "subject is hello world";
  
  if(regex_match(s, rgx)) { // regex match on string
    cout << "PRESENT\n";
  } else {
    cout << "NOT PRESENT\n";
  }
  
  getline(cin, s);
  if(regex_match(s, rgx)) {
    cout << "PRESENT\n";
  } else {
    cout << "NOT PRESENT\n";
  }
  
  if(regex_match(s.begin(), s.end(), rgx)) { // regex match on string with iterator. You can change the range as well
    cout << "PRESENT\n";
  } else {
    cout << "NOT PRESENT\n";
  }
  
  
  return 0;
}
