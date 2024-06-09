// || जय जय जय बजरंग बली ||

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**
Problem Link :: https://leetcode.com/problems/coin-change/description/?envType=problem-list-v2&envId=55ac4kuc
Problem type :: Minimum (Maximum) Path to Reach a Target.
Statetment type :: Given a target find minimum (maximum) cost / path / sum to reach the target.

Approach :: DP
Time :: O(amount)
Space :: O(amount)


**/


    vector<int> dp;

    int solve(vector<int>& coins, int x) {
        if(x == 0) {
            return 0;
        }
        if(x < 0) {
            return -1;
        }
        if(dp[x] != -5) {
            return dp[x];
        }

        int ans = -1;
        for(int i=0; i<coins.size(); i++) {
            int val = solve(coins, x - coins[i]);
            if(val != -1) {
                if(ans == -1) {
                    ans = 1 + val;
                } else {
                    ans = min(ans, val+1);
                }
            }
        }
        return dp[x] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        
        dp.resize(amount+1);
        for(int i=0; i<=amount; i++) {
            dp[i] = -5;
        }
        int ans = solve(coins, amount);
        return ans;

    }

int main() {
    
    int n;
    cin >> n;
    
    vector<int> coins(n);
    for(int i=0; i<n; i++) {
        cin >> coins[i];
    }
    int amount;
    cin >> amount;
    
    int ans = coinChange(coins, amount);
    cout << ans << '\n';
    
    return 0;    
}
