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
  
  
  // \d can be used as an equivalent to [0-9] i.e any character in range 0 to 9
  // \D can be used as an equivalent to [^0-9] i.e any character not in range 0 to 9
  
  string s = "1375fs df34";
  
  regex rgx("\\d");
  regex rgx2("\\D");
  
  printAllMatches(s, rgx);
  cout << '\n';
  printAllMatches(s, rgx2);
  cout << '\n';
  
  s = "123 45645 323 r2324341 112 fmkf32320smv ";
  // get all the strings having only number and length >= 4 and <= 8.
  
  regex rgx3("\\d{4,8}");
  
  printAllMatches(s, rgx3);
  cout << '\n';
   
   
  // \w can be used as an equivalent [a-zA-Z0-9_] i.e uppercase, lowercase, numeric and underscore
  // \W can be used as an equivalent [^a-zA-Z0-9_]
  
  s = "423-873-1259 12e-23e-8921 1323-wqe-1221 141-11_-0929 133-131- 1931";
  
  // print all  strings of type xxx-xxx-xxxx where x can be a-z A-Z 0-9 or _
  
  regex rgx4("\\w{3}-\\w{3}-\\w{4}");
  
  printAllMatches(s, rgx4);
  cout << '\n';
  
  
  
  // \s can be used as an equivalent [\f\n\r\t\v]
  // \S can be [^\f\n\r\t\v]
  
  s = "Rajveersinh Gohil\nis best";
  
  regex rgx5("\\w{2,20}\\s\\w{2,20}\\s\\w{2,20}");
  printAllMatches(s, rgx5);
  cout << '\n';
  
  return 0;
}
