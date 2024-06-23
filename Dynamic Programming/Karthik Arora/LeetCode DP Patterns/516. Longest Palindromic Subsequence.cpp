class Solution {
public:

    int dp[1001][1001];

    int longestPalindromeSubseq(string s) {
        memset(dp, 0, sizeof(dp));

        int n = s.length();
        for(int i=1; i<=n; i++) {
            dp[i][i] = 1;
        }

        //dp[i][j] = longest pallindrome from index i to j in string

        //go diagonally . If s[i] == s[j] then ans = 2 + longest pallindrome from i+1 to j-1. Else :: ans = max(longest from i to j-1, longest from i+1 to j)

        for(int it=2; it <= n; it++) {
            int row = 1, col = it;
            while(col <= n) {
                if(s[row-1] == s[col-1]) {
                    int val = 2 + dp[row+1][col-1];
                    dp[row][col] = val;
                } else {
                    int val = max({dp[row+1][col], dp[row][col-1]});
                    dp[row][col] = val;
                }

                row++;
                col++;
            }
        }

        return dp[1][n];
    }
};class Solution {
public:

    int dp[1001][1001];

    int longestPalindromeSubseq(string s) {
        memset(dp, 0, sizeof(dp));

        int n = s.length();
        for(int i=1; i<=n; i++) {
            dp[i][i] = 1;
        }

        //dp[i][j] = longest pallindrome from index i to j in string

        //go diagonally . If s[i] == s[j] then ans = 2 + longest pallindrome from i+1 to j-1. Else :: ans = max(longest from i to j-1, longest from i+1 to j)

        for(int it=2; it <= n; it++) {
            int row = 1, col = it;
            while(col <= n) {
                if(s[row-1] == s[col-1]) {
                    int val = 2 + dp[row+1][col-1];
                    dp[row][col] = val;
                } else {
                    int val = max({dp[row+1][col], dp[row][col-1]});
                    dp[row][col] = val;
                }

                row++;
                col++;
            }
        }

        return dp[1][n];
    }
};
