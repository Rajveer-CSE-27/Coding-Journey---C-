#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;


/**
ou are given the following:
Two integers ( N ) and ( K ) An array ( A ) of size ( N )
Let sequence 𝐵=(𝐵1,𝐵2,…,𝐵2𝐾)) of size 2K be a subsequence of array A .
Let's define F(B) as:
𝐹(𝐵)=[(𝐵1|𝐵2|…|𝐵𝐾)⊕(𝐵𝐾+1|𝐵𝐾+2|…|𝐵2𝐾)]
Where | denotes the bitwise OR operation and ⊕ denotes the bitwise XOR operation.
Task
Determine the maximum value of F(B) for all possible sequences B .
[1≤𝑇≤102] [2≤𝑁≤1001] [1≤𝐾≤⌊𝑁2⌋] [0≤𝐴𝑖<27]
Note: A sequence ( X ) is a subsequence of sequence ( Y ) if ( X ) can be obtained from ( Y ) by deleting several (possibly zero or all) elements without changing the order of the remaining elements.


Solution link :: https://codeforces.com/blog/entry/131608
Check the comment section

**/

bool isSubMask(int a, int b){
  
  return ((a | b) == b);
}

int solve(int& n, int& k, vector<int>& vc) {
  
  vector<int> pref(130, -1), suff(130, -1);
  // pref[i] = leftmost index in array where valid or sequence of k values exist giving or = i
  // suff[i] = rightmost index in array where valid or sequence of k values exist giving or = i
  
  vector<int> dp(128, 1e9);
  // dp[i] = minimum count of elements required such that OR of all those elements  = i
  
  vector<int> cnt(128, 0);
  // cnt[i] = submasks of the mask(i) i.e maximum number of elements that we can consider in taking OR to get this mask
  
  
  for(int i=0; i<n; i++) {
    
    dp[vc[i]] = 1;
    for(int mask=0; mask < 128; mask++) {
      
      dp[mask | vc[i]] = min(dp[mask | vc[i]], 1 + dp[mask]); // that is considering element vc[i] with mask
      if(isSubMask(vc[i], mask) == true) {
        cnt[mask]++;
      } 
      
    }
    
    for(int mask = 0; mask < 128; mask++) {
      
      if(dp[mask] <= k and cnt[mask] >= k and pref[mask] == -1) {
        pref[mask] = i;
      }
      
    }
  }
  
  
  dp.clear();
  cnt.clear();
  
  dp.resize(128, 1e9);
  cnt.resize(128, 0);
  
  for(int i=n-1; i>=0; i--) {
    
    dp[vc[i]] = 1;
    for(int mask=0; mask < 128; mask++) {
      
      dp[mask | vc[i]] = min(dp[mask | vc[i]], 1 + dp[mask]); // that is considering element vc[i] with mask
      if(isSubMask(vc[i], mask) == true) {
        cnt[mask]++;
      } 
      
    }
    
    for(int mask = 0; mask < 128; mask++) {
      
      if(dp[mask] <= k and cnt[mask] >= k and suff[mask] == -1) {
        suff[mask] = i;
      }
      
    }
    
  }
  
    
  for(int mask = 127; mask >= 0; mask--) {
    
    for(int leftPart = 127; leftPart >= 0; leftPart--) {
      int rightPart = mask^leftPart;
      
      if(pref[leftPart] != -1 and suff[rightPart] != -1 and pref[leftPart] < suff[rightPart]) {
        return mask;
      }
    }
  }
  
  return 0;
}

int main() {
  
  int n,k;
  cin >> n >> k;
  vector<int> vc(n);
  for(int i=0; i<n; i++) {
    cin >> vc[i];
  }
  
  cout << solve(n,k,vc);
  
  
  return 0;
  
}
