class Solution {
public:

    map<int, map<int, double>> dp; // dp likhne ka tareeka when size if unknown
    double fun(int a, int b) {
        if(a <= 0 and b <= 0) {
            return 0.5;
        }
        if(a <= 0) {
            return 1;
        }
        if(b <= 0) {
            return 0;
        }   

        if(dp[a].count(b) != 0) { // similar to step where we check dp[i][j] != -1
            return dp[a][b];
        }

        return dp[a][b] = 0.25 * (fun(a-4, b) + fun(a-3, b-1) + fun(a-2, b-2) + fun(a-1, b-3));

    }

    double soupServings(int n) {
        int m = ceil((double)n/25);

        for(int i=1; i<=m; i++) {
            if(fun(i,i) > 1 - 1e-5) { // becuase ek certain m ke baad answer humesha 1 aega becuase probability that a finishes first will always tend to 1 after some value of m. Because initial staring point is m for both. For proof and intuition see this video https://www.youtube.com/watch?v=XNLJS-uDIqU

                // because as we increase i the probabilty or our answer increases. Hence if ans > 1 - 1e-5 then answer will later increase only and our result will always be 1 after that
                return 1;
            }
            
        }
        return fun(m,m);

    }
};
