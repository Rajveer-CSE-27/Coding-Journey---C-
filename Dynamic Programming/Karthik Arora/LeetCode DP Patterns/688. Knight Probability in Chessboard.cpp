class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> dp(n, vector<double>(n, 0));
        dp[row][column] = 1.0;
        // dp[i][j] = probability of knight that it reaches at cell(i,j) in current iteration.
        
    
        vector<pair<int,int>> knightMove(8);
        knightMove[0] = {1,2};
        knightMove[1] = {1,-2};
        knightMove[2] = {-1,2};
        knightMove[3] = {-1,-2};
        knightMove[4] = {2,-1};
        knightMove[5] = {2,1};
        knightMove[6] = {-2,-1};
        knightMove[7] = {-2,1};
        // this tells us how a knight can move

        for(int move=1; move<=k; move++) {
           vector<vector<double>> tempDp(n, vector<double>(n, 0));

            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    for(int l=0; l<8; l++) {
                        if(i + knightMove[l].first >=0 and i + knightMove[l].first < n and j + knightMove[l].second >=0 and j + knightMove[l].second < n) {
                            double val = dp[i +knightMove[l].first][j + knightMove[l].second]/8.0;
                            tempDp[i][j] += val;
                        }
                    }
                }
            }
            dp = tempDp;
        }

        double ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                ans += dp[i][j];
            }
        }
        return ans;
    }
};
