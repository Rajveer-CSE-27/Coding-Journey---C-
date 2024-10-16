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
  
  string s = "I picked the pickles";
  
  // find all matches such that each match start with pick 
  
  regex rgx("(pick([^ ]+)?)");
  
  // sab kuch "()" ke andar hona chahiye
  // sabse pehle tumhe pick to chahiye hi to "(pick likh diya
  // uske baad tumhe >= 1 characters aise chahiye jo space na ho to : ([^ ]+) likh diya 
  // + ye bolta hai ki previous jo likha hua hai vo multiple times execute hoga unless false na ho. To jab tak space naa aye tab tak characters add hote rahenge.
  // uske baad ? isiliye add kiya taaki pick wala string bhi hum consider kare.
  // harr new cheeze ko bracket me daalte raho
  
  
  printAllMatches(s, rgx);
  
  return 0;
}
