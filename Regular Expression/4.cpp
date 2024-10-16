#include <bits/stdc++.h>
#include <regex>
using namespace std;


/**
https://www.youtube.com/watch?v=9K4N6MO_R1Y&t=7s
**/



int main() {
  
  string s = "Cat rat mat fat pat catia at";
  
  // replace all strings that start with C or r and next two characters at with string "Hello"
  regex rgx("([Cr]at)");
  
  string res = regex_replace(s, rgx, "Hello");
  cout << res;
   
  
  return 0;
}
