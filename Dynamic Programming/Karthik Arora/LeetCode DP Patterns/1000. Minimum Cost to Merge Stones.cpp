class Solution {
public:

    int dp[41][41][41];
    vector<int> prefixSm;

    int fun(int i, int j, int p, int& k) {
        // this will tell minimum cost to convert elements from i to j into p piles.
        if(i == j and p == 1) {
            // its already 1 pile hence cost = 0;
            return 0;
        }
        if(i == j) {
            // we cannot make >1 piles from 1 element only
            return INT_MAX/4;
        }

        if(dp[i][j][p] != -1) {
            return dp[i][j][p];
        }

        if(p == 1) {
            // minimum cost to make 1 pile from i to j is equal to minimum cost to make k piles from i to j and then converting those k piles to 1 pile by adding all elements from i to j

            int ans = fun(i,j,k,k);
            if(i == 0) {
                ans += prefixSm[j];
            } else {
                ans += prefixSm[j] - prefixSm[i-1];
            }
            return dp[i][j][p] = ans;
        }

        // if p > 1 then we will try to make 1 pile between i to t for all t = i to j-1 and remaining p-1 piles from t+1 to j and get min ans

        int ans = INT_MAX/4;
        for(int t = i; t < j; t++) {
            int val = fun(i,t,1,k) + fun(t+1,j, p-1, k);
            ans = min(ans, val);
        }
        return dp[i][j][p] = ans;
    }

    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();

        /**
        Checking whether we can merge given n piles into 1 pile by taking k piles at once and converting it to 1 pile.

        After 1 operation : piles left = n - k + 1 // because we are removing k piles and adding 1 pile
                                       = n - (k - 1);
            
              2 operations : piles left = (n - k + 1) - k + 1 = n - 2*k + 2 = n - 2*(k - 1)
              3 operations : n - 3*(k - 1)
              ..

              let after m operations we have 1 pile left
              so n - m*(k - 1) = 1
              (n - 1) - m*(k - 1) = 0
              (n - 1) = m*(k-1)
              (n - 1)/(k - 1) = m
              
              and m must be an integer. Hence (n-1)%(k-1) == 0 for success
        **/

        if((n-1)%(k-1) != 0) {
            return -1;
        }

        int sm = 0;

        for(int i=0; i<n; i++) {
            sm += stones[i];
            prefixSm.push_back(sm);
        }

        memset(dp, -1, sizeof(dp));
        int ans = fun(0, n-1, 1, k);

        return ans;

    }
};
