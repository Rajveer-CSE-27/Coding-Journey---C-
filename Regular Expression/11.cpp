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
  
  string s = "Just some words\nadd some more\r\nadd more\n";
  
  // replace all \n or \r\n with a space
  
  regex rgx("\r?\n");
  
  // here we are checking if there is \r\n or just \n and replacing it.
  
  string ans = regex_replace(s, rgx, " ");
  cout << ans << '\n';
  
  
  s = "<name> The big bang theory</name> <name> Friends </name> </name> Ben10 <name>";
  
  // Grab all the strings between <name> </name> individually
  
  regex rgx2("<name>(.*?)</name>");
  
  // (.*) agar karte to vo maximum length ki string possible between <name> </name> deta
  // i.e ouput :: <name> The big bang theory</name> <name> Friends </name> </name>
  
  // (.*?) by doing this we are telling that jabhi bhi <name> ke baad </name> dikhe to usko ek valid matching declare kar dena.
  // hence shortest length ki matching dhundhta hai.
  
  // hum +? kar sakte hai to do shortest matching (of len >= 1) and {n1,n2}? bhi kar sakte hai.
  
  printAllMatches(s, rgx2);
  
  
  return 0;
}
