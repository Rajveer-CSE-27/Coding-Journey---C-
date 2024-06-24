class Solution {
public:

    bool dp[1001][1001];

    int countSubstrings(string s) {
        memset(dp, false, sizeof(dp));
        // dp[i][j] = true if there exist pallindrome from i to j in string;

        int n = s.length();
        for(int i=0; i<n; i++) {
            dp[i][i] = true;
        }

        // handle cases with len = 2;
        for(int i=0; i<n-1; i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = true;
            }
        }

        for(int it=2; it<n; it++) {
            int row = 0, col = it;
            while(col < n) {

                if(s[row] == s[col]) {
                    if(dp[row+1][col-1] == true) {
                        dp[row][col] = true;
                    }
                }

                row++;
                col++;
            }
        }

        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(dp[i][j] == true) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
