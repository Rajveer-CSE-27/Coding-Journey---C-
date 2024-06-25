class Solution {
public:
    
    int numDistinct(string s, string t) {
       int n = s.length(), m = t.length();
       long double dp[n][m];
       // NOTE :: yaha long double ya double use karro isse integer overflow nhi aega

       memset(dp, 0, sizeof(dp));
        // dp[i][j] = number of valid subsequences that can be generated such that current element that we need to insert at the end of subsequence is t[j] and we are currently standing at s[i] in string i.
        
        // if s[i] == t[j] then dp[i][j] = dp[i-1][j-1] :: number of valid subsequences till j-1 in string t such that we were at i-1 in s. Because s[i] and t[j] are equal.

        // also for any case :: dp[i][j] += dp[i-1][j] :: number of valid subsequences till j in string t such that we were at i-1 in s.


       if(s[0] == t[0]) {
            dp[0][0] = 1;
       } else {
            dp[0][0] = 0;
       }

       for(int i=1; i<n; i++) {
            for(int j=0; j<=min(i, m-1); j++) {
                if(s[i] == t[j]) {
                    if(j==0) {
                        dp[i][j] += 1;
                    } else {
                        dp[i][j] += dp[i-1][j-1];
                    }
                }
                dp[i][j] += dp[i-1][j];
            }
       }
       return dp[n-1][m-1];
    }
};
