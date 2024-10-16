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
  
  string s = "F.B.I. I.R.S. CIA C.BI";
  
  // print all string matches of type a.b.c. where a, b, c are any characters 
  
  regex rgx("([^ ]\\..\\..\\.)");
  // [^ ] means first character is anything except space
  // \\. means next character is '.' Becaue . is a special character in regex we must create escape sequence of it
  // next . means any character 
  // \\. means next character is '.'
  // and so on

  printAllMatches(s, rgx);
   
  
  return 0;
}
