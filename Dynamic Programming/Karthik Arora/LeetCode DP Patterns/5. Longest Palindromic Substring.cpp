class Solution {
public:

    int dp[1001][1001];

    string longestPalindrome(string s) {
        s = "#" + s;
        int n = s.length()-1;

        // dp[i][j] = index of the last character in string for the longest pallindrome that starts from i and ends on or before j

        for(int i = 1; i <= n; i++) {
            dp[i][i] = i;
        }
        for(int it = 2; it <= n; it++) {
            int row = 1, col = it;
            while(col <= n) {

                if(s[row] == s[col]) {
                    if(row + 1 == col) {
                        dp[row][col] = col;
                    } else if(dp[row+1][col-1] == col-1) {
                        dp[row][col] = col;
                    } else {
                        dp[row][col] = dp[row][col-1];
                    }
                } else {
                    dp[row][col] = dp[row][col-1];
                }

                col++;
                row++;
            }
        }

        int len = 0;
        int r, c;
        for(int i=1; i<=n; i++) {
            for(int j=i; j<=n; j++) {
                if(dp[i][j] - i + 1 > len) {
                    len = dp[i][j] - i + 1;
                    r = i;
                    c = dp[i][j];
                }
            }
        }
        string res = "";
        for(int i=r; i<=c; i++) {
            res += s[i];
        }
        return res;
    }
};
