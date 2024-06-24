class Solution {
public:

    int dp[1001][1001];
    int n,m;
    string str1, str2;

    int fun(int i, int j) {
        if(i == n or j == m) {
            int ans = 0;
            while(i < n) {
                ans += (int)str1[i];
                i++;
            }
            while(j < m) {
                ans += (int)str2[j];
                j++;
            }
            return ans;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(str1[i] == str2[j]) {
            int ans = fun(i+1, j+1);
            return dp[i][j] = ans;
        }
        
        // delete from first string
        int val1 = (int)str1[i] + fun(i+1,j);

        // delete from 2nd string
        int val2 = (int)str2[j] + fun(i, j+1);

        int ans = min(val1, val2);
        return dp[i][j] = ans;
    }

    int minimumDeleteSum(string s1, string s2) {
        n = s1.length(), m = s2.length();
        str1 = s1;
        str2 = s2;

        memset(dp, -1, sizeof(dp));
        int ans = fun(0,0);
        return ans;
    }
};
