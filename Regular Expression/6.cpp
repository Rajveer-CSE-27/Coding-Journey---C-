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
  
  
  string s = "This is a\nmultiline string that has \nmultiple lines";
  cout << s << '\n';

  // convert this string to single line using regex
  
  regex rgx("\n"); // if you want to find string chars like \n \t \b etc do not use () in regex.
  
  
  string ans = regex_replace(s, rgx, " "); // replacing \n with space
  cout << ans;
  
  /**
  You can also replace :: 
    \b :: backspace
    \f :: form feed
    \r :: Carriage return
    \t :: tab
    \v :: vertical tab
  
  **/
  
   
  
  return 0;
}
