class Solution {
public:

    int dp[501][501];
    int n,m;
    string s1, s2;
    int fun(int i, int j) {

        if(i == n or j == m) {
            int val = max(n - i, m - j);
            return val;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s1[i] == s2[j]) {
            return dp[i][j] = fun(i+1, j+1);
        }

        // insert at s1 or delete at s2
        int val1 = 1 + fun(i,j+1);
        // insert at s2 or delete at s1
        int val2 = 1 + fun(i+1,j);
        // replace
        int val3 = 1 + fun(i+1, j+1);

        int ans = min({val1, val2, val3});
        return dp[i][j] = ans;
    }

    int minDistance(string word1, string word2) {
        n = word1.length();
        m = word2.length();
        s1 = word1;
        s2 = word2;
        
        memset(dp, -1, sizeof(dp));
        int ans = fun(0, 0);
        return ans;
    }
};
