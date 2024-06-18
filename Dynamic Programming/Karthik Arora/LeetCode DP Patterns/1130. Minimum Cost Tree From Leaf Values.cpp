class Solution {
public:

    int dp[41][41];

    int mxDp[41][41];

    int fun(int i, int j, vector<int>& arr) {
        if(i >= j) {
            return 0;
        }
        if(i+1 == j) {
            return arr[i]*arr[j];
        }
    
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = INT_MAX;
    
        for(int left = i; left < j; left++) {
            int val = fun(i, left, arr) + fun(left+1, j, arr) + (mxDp[i][left]*mxDp[left+1][j]);
        
            ans = min(ans, val);
        }
    
        return dp[i][j] = ans;
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();

        memset(mxDp, 0, sizeof(dp));
    
        for(int i=0; i<n; i++) {
            int mx = 0;
            for(int j=i; j<n; j++) {
                mx = max(mx, arr[j]);
                mxDp[i][j] = mx;
            }
        }       

        memset(dp, -1, sizeof(dp));
        int ans = fun(0, n-1, arr);

        return ans;
    }
};
