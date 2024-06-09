// || जय जय जय बजरंग बली ||

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**
Problem Link :: https://leetcode.com/problems/minimum-cost-for-tickets/description/?envType=problem-list-v2&envId=55ac4kuc
Problem type :: Minimum (Maximum) Path to Reach a Target.
Statetment type :: Given a target find minimum (maximum) cost / path / sum to reach the target.

Approach :: DP.
            Form a dp[n] array.
            dp[i] = minimum cost such that you start from day[i] element.
            Base case : dp[n-1] = min_element from cost
            
        Recurrence ::
            let at element x = day[i];
            Find 3 elements in array with lowerbound function. x+1, x+7, x+30 = x1, x2, x3 with index i1,i2,i3
            dp[i] = min(costs[0] + dp[i1], costs[1] + dp[i2], costs[2] + dp[i3])
            
        dp[0] is your answer.
        Handle edge cases such that x+1 or x+7 or x+30 do not exist in days array.
        
Time :: O(nlogn)
Space :: O(n)



**/


int mincostTickets(vector<int>& days, vector<int>& costs) {
    
        int n = days.size();
        int dp[n];
        
        dp[n-1] = *min_element(costs.begin(), costs.end());
        
        for(int i=n-2; i>=0; i--) {
            int day = days[i];
            int x1 = day + 1;
            int x2 = day + 7;
            int x3 = day + 30;

            auto it1 = lower_bound(days.begin(), days.end(), x1);
            auto it2 = lower_bound(days.begin(), days.end(), x2);
            auto it3 = lower_bound(days.begin(), days.end(), x3);

            int c1 = costs[0], c2 = costs[1], c3 = costs[2];
            if(it1 != days.end()) {
                int index = it1 - days.begin();
                c1 += dp[index];

            }
            if(it2 != days.end()) {
                int index = it2 - days.begin();
                c2 += dp[index];
            }
            if(it3 != days.end()) {
                int index = it3 - days.begin();
                c3 += dp[index];
            }
            dp[i] = min({c1,c2,c3});
        }

        return dp[0];
        
    }

int main() {
    
    int n;
    cin >> n;
    
    vector<int> days(n), costs(3);
    for(int i=0; i<n; i++) {
        cin >> days[i];
    }
    for(int i=0; i<3; i++) {
        cin >> costs[i];
    }
    
    int ans = mincostTickets(days, costs);
    cout << ans << '\n';
    
    return 0;    
}
