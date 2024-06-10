class Solution {
public:
    int minSteps(int n) {
        int dp[1001];
        dp[1] = 0;
        dp[2] = 2;
        dp[3] = 3;

        for(int i=4; i<=n; i++) {
            bool flag = true;
            for(int j=2; j*j <= i; j++) {
                if(i%j == 0) {
                    dp[i] = dp[j] + dp[i/j];
                    flag = false;
                    break;
                }
            }
            if(flag == true) {
                dp[i] = i;
            }
        }
        return dp[n];

    }
};
