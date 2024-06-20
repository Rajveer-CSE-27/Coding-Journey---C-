class Solution {
public:

    int dp[305][305];
    int n;

    int solve(int i, int j, vector<int>& vc) {

        if(i+2 > j) {
            return 0;
        }

        // first and last element are multipliers
        if(i+2 == j) {
            return vc[i]*vc[i+1]*vc[i+2];
        }

        if(dp[i+1][j-1] != -1) {
            return dp[i+1][j-1];
        }

        int ans = -1;
        for(int k=i+1; k<j; k++) {

            // we are bursting kth balloon at the end hence vc[i] and vc[j] will be its multipliers.
            int val = vc[i]*vc[k]*vc[j];

            val += solve(i, k, vc) + solve(k, j, vc);
            ans = max(ans, val);
        }
        return dp[i+1][j-1] = ans;
    }

    int maxCoins(vector<int>& nums) {
        vector<int> vc;
        vc.push_back(1);
        for(int x:nums) {
            vc.push_back(x);
        }
        vc.push_back(1);

        int n = vc.size();

        memset(dp, -1, sizeof(dp));
        int ans = solve(0, n-1, vc);
        return ans;
    }
};
