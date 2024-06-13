// See link for solution image :: https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/solutions/791203/c-dynamic-programming-backtracking-with-figure-explained-100-faster
class Solution {
public:

    vector<vector<int>> dp;

    // n <= m always here
    int solve(int n, int m) {
        if(dp[n][m] != -1) {
            return dp[n][m];
        }
        if(n == m) {
            return dp[n][m] = 1;
        }
        if(n == 0 or m == 0) {
            return 0;
        }
        if(n == 1) {
            return m;
        }

        // Case 1 :: breaking n*m rectangle into 1 square of n*n and another rectangle (m-n)*n;
        int next_n = min(n,m);
        int next_m = max(n,m) - next_n;

        // NOTE : solve(n,m) me n <= m rakho
        int ans = solve(min(next_n,next_m), max(next_n,next_m)) + 1;

        /** Case 2 :: breaking n*m rectangle into 2 squares and 3 rectangles.
        Square 1 :: s*s bottom left corner.
        Square 2 :: k*k top right corner.
        Rectangle 1 :: upper rectangle :: b * (m-k)
        Rectangle 2 :: middle rectangle :: x * y
        Rectangle 3 :: lower rectangle :: (n-k) * a

        Iterate for all values of s and k.
        Write x,y,b,a in terms of n,m,s,k
        Get the minimum result
        **/

        // max value s can take is min(n,m) i.e = next_n. Usse bada nahi hoga
        for(int s=next_n; s>0; s--) {

            int a = max(abs(n-s), abs(m-s)); // larger side
            int b = min(abs(n-s), abs(m-s)); // smaller side this will go with k*k square

            for(int k=b; k<=a and k<=n; k++) {

                int x = min(abs(a-k), abs(b-k));
                int y = max(abs(a-k), abs(b-k));

                int rect1 = solve(min(b,m-k), max(b,m-k));
                int rect2 = solve(x,y);
                int rect3 = solve(min(n-k,a), max(n-k,a));

                int ans2 = rect1 + rect2 + rect3 + 2; // we added 2 because of 2 squares i.e s*s and k*k

                ans = min(ans, ans2);
            }
        }
        return dp[n][m] = ans;

    }

    int tilingRectangle(int n, int m) {
        
        int x = min(n,m);
        int y = max(n,m);
        dp.resize(x+1, vector<int>(y+1, -1));

        int ans = solve(x,y);
        return ans;
    }
};
