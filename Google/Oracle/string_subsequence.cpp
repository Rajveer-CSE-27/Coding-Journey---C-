#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int N = 1000001;

/**
https://www.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
**/

class Solution {
  public:
  
  
    const int mod = 1e9 + 7;
  
    int countWays(string s1, string s2) {
        // code here
        
        int n = s1.length(), m = s2.length();
        vector<int> dp(n,0);
        
        int cnt = 0;
        
        for(int i=0; i<n; i++) {
            if(s1[i] == s2[0]) {
                cnt++;
            }
            dp[i] = cnt;
        }
        
        for(int i=1; i<m; i++) {
            vector<int> dp2(n,0);
            cnt = 0;
            
            for(int j=0; j<n; j++) {
                
                if(s1[j] == s2[i]) {
                    if(j-1 >= 0) {
                        cnt += dp[j-1];
                        cnt %= mod;
                    }
                }
                
                dp2[j] = cnt;
                
            }
            dp = dp2;
            
        }
        return dp[n-1];
    }
};

int main() {
  
  
  
  return 0;  
}
