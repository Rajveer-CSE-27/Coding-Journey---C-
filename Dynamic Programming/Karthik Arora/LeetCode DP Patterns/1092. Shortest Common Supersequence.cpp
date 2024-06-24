class Solution {
public:
    int dp[1001][1001];
    bool dpCheck[1001][1001];

    int n,m;
    string s1, s2;
    
    int fun(int i, int j) {
        if(i == n and j == m) {
            return 0;
        }
        if(i == n) {
            dpCheck[i][j] = false;
            int val = 1 + fun(i,j+1);
            return dp[i][j] = val;
        }
        if(j == m) {
            dpCheck[i][j] = true;
            int val = 1 + fun(i+1,j);
            return dp[i][j] = val;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s1[i] == s2[j]) {
            int val = 1 + fun(i+1, j+1);
            return dp[i][j] = val;
        }
        int val1 = 1 + fun(i+1, j);
        int val2 = 1 + fun(i, j+1);

        if(val1 <= val2) {
            dpCheck[i][j] = true;
            return dp[i][j] = val1;
        }
        dpCheck[i][j] = false;
        return dp[i][j] = val2;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        n = str1.length();
        m = str2.length();
        s1 = str1;
        s2 = str2;

        memset(dp, -1, sizeof(dp));
        int mnLen = fun(0,0);
        int i = 0, j = 0;

        string res = "";
        while(mnLen--) {
            if(i < n and j < m) {
                if(s1[i] == s2[j]) {
                    res += s1[i];
                    i++;
                    j++;
                } else {
                    if(dpCheck[i][j] == true) {
                        res += s1[i];
                        i++;
                    } else {
                        res += s2[j];
                        j++;
                    }
                }
            } else if(i == n and j == m) {
                break;
            } else if(i == n) {
                res += s2[j];
                j++;
            } else {
                res += s1[i];
                i++;
            }
        }

        return res;
    }
};
