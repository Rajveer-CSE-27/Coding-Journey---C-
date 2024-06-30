// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**
https://www.youtube.com/watch?v=heUFId6Qd1A&list=PLb3g_Z8nEv1hB69JL9K7KfEyK8iQNj9nX

Digit DP concept ::
    -> Used to solve 2 types of problems ::
    
        Type 1 ::   need to find all the x in range [0,R] which follows something like f(x). 
                    But here R is large like 10^18, or even 10^1000. iterating over all values between 0 to R won't work.
        
        Type 2 ::   need to find all the x in range [L,R] which follows something like f(x). 
                    But here R is large like 10^18 and L might be large or small.
            
                Note :: Type 2 problem can be solved by solving Type 1 problem. Ans = solve(0,R) - solve(0, L-1)
            
Example problem :: 
    Find the count of numbers between L and R which have a sum of digits = X.
    1 <= L <= R <= 10^18
    1 <= X <= 180.
    
Approach :: 
    
    Obtain the solution for :: (0,9), (0,99), (0,999), (0,9999), ... ranges
    Use them to solve for any range (L,R).
    
    Let L = 0, R = 82741
    X = 15
    
    Let dp(i,X) = number of values between 0 to i such that sum of its digit = X
    
    solve(82741, X) : 
        now total digits = 5.
        int ans = 0;
        5th digit from left :: 
                if(digit >= 0 and < 8) {
                    ans += solve(9999, X - digit)
                } else if(digit == 8) {
                    ans += solve(2741, X - 8)
                }
                
    solve(2741, X) :
        total digits = 4;
        int ans = 0;
        4th digit from left ::
                if(digit >= 0 and < 2) {
                    ans += solve(999, X - digit);
                } else if(digit == 2) {
                    ans += solve(741, X - 2);
                }
    and so on......
    
    This is how we use digit dp.
    
    Use the numbers in the form of digits.
    dp[n][x] will tell us how many numbers with maximum digits = n will have sum = x
    
**/

int dp[20][181][2];

int solve(string& s, int n, int x, bool tight) {
    
    // this will give us number values till max n digits which have sm = x.
    // if tight is true then we need to take care of leftmost value. And do not consider any leftmost digit > leftmost value in given string
    
    if(x < 0) {
        return 0;
    }
    
    if(n == 1) {
        if(x >= 0 and x <= 9) {
            return 1;
        }
        return 0;
    }
    
    if(dp[n][x][tight] != -1) {
        dp[n][x][tight] != -1;
    }
    
    int upper_bound_leftmost = 9;
    if(tight == true) {
        int d = s[s.length() - n] - '0';
        upper_bound_leftmost = d;
    }
    
    int ans = 0;
    for(int i=0; i<=upper_bound_leftmost; i++) {
        
        if(tight == true and i == upper_bound_leftmost) {
            ans += solve(s, n-1, x-i, true);
        } else {
            // now there is no bound because leftmost < upper_bound_leftmost
            ans += solve(s, n-1, x-i, false);
        }
        
        
    }
    return dp[n][x][tight] = ans;
    
}

int main() {
    
    string r;
    cin >> r;
    int x;
    cin >> x;
    
    
    memset(dp, -1, sizeof(dp));
    int ans = solve(r, r.length(), x, true);
    cout << ans;
    
    
    return 0;
}
