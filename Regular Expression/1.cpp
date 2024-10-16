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
  
 
  string s = "The ape was at apex"; // this is the string on which we will be performing things.
  regex rgx("(ape[^ ]?)"); // this is the pattern. Humesha "()" ke andar hi daalna
  
  // () jab tak possible ho () naa hi use karo to better rahgea. Isse time complexity badhegi
  // ape[^ ] : we want all strings that start with ape and then any character except a space.
  // [^ ] this means not a space
  // ? That is after ape if there is nothing then ape would also be considered as a match
  
  printAllMatches(s, rgx);
  
  return 0;
}
