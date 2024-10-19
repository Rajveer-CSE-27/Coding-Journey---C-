#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

template <class key, class Comp = less<key>>
using pbds = tree<key, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update>;

/**

We have a binary string S of length N, and we have to find the number of substrings(that is, a contiguous range i to j) in which the frequency of 1 is strictly greater than the frequency of 0.
Constraints : 1<=N<=1e6;


Approach :: 
1.replace each 0 with -1
2.calculate prefix sum of newly formed array after replacement
3.now we have to find the number of sub-arrays who's sum is > 0.
4.let's say we have to find the sub-arrays ending at index j.
5.then sub-array [i,j] has +ve sum iff, pref[j] — pref[i-1] > 0 =>pref[j] > pref[i-1]
6.it means we have to find number of elements pref[i] which are smaller than pref[j] such that i < j.


PBDS
**/


void solve() {
  
  string s;
  cin >> s;
  int n = s.length(); 
  
  pbds<pair<ll, ll>> p;
  p.insert({0, 0});

  ll ans = 0, diff = 0, id = 0;
  
  for(int i=0; i<n; i++) {
    
    diff += (s[i] == '1' ? 1 : -1);
    
    p.insert({diff, id++});
    ans += p.order_of_key({diff, -1});
  }
  
  cout << ans;
  
}

  
int main() {
  
  
  
  
  return 0;
  
}
