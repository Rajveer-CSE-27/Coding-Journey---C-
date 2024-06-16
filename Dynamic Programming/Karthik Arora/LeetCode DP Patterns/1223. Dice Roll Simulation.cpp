class Solution {
public:

    const int mod = 1e9 + 7;
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<long long>> dp(7, vector<long long>(16, 0));

        // NOTE :: Roll max is not 1 indexed. It's 0-indexed

        for(int i=1; i<=6; i++) {
            dp[i][1] = 1;
        }

        //dp[i][j] = total distinct sequences at current round such that in current round we  throw dice with face = i for jth consecutive time. 

        for(int roll=2; roll<=n; roll++) {
            vector<vector<long long>> tempDp(7, vector<long long>(16));

            for(int i=1; i<=6; i++) {
                for(int j=1; j<=15; j++) {
                    if(j > roll) {
                        tempDp[i][j] = 0;
                    } else if(j > rollMax[i-1]) {
                        tempDp[i][j] = 0;
                    } else if(j > 1) {
                        tempDp[i][j] = dp[i][j-1];
                    } else {
                        long long ans = 0;
                        for(int l=1; l<=6; l++) {
                            if(l != i) {
                                for(int s=1; s<=15; s++) {
                                    ans = (ans + dp[l][s])%mod;
                                }
                            }
                        }
                        tempDp[i][j] = ans;
                    }
                }
            }
            dp = tempDp;
        }
        long long sm = 0;
        for(int i=1; i<=6; i++) {
            for(int j=1; j<=15; j++) {
                sm = (sm + dp[i][j])%mod;
            }
        }
        return sm;
    }
};
