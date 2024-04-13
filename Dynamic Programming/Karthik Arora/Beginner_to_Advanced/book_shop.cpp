#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Problem link :: https://cses.fi/problemset/task/1158/

Approach :: 
        Form the recursion tree with index number of book and maximum total price = x. 
        Use the book atmost 1 time only.
        
        We can form a dp[i][j] :: i = index of the current book, j = money left to spenc.
        Find dp[i][j] for each i from [1,n] that is for each book with j = [0,x]
        
        dp[i][j] = maximum number of pages that can be obtained starting with current book[i] with money left = j.
        Note :: we only move forward from a given i. If we have crossed a book we never come back.
        
        
**/

int main() {
    
    int n,x;
    cin >> n >> x;
    
    vector<int> price(n+1), page(n+1);
    
    for(int i=1; i<=n; i++) {
        cin >> price[i];
    } 
    for(int i=1; i<=n; i++) {
        cin >> page[i];
    } 
    
    vector<vector<int>> dp(n+1, vector<int>(x+1));
    
    for(int money=0; money<=x; money++) {
        if(money < price[n]) {
            dp[n][money] = 0;
        } else {
            dp[n][money] = page[n];
        }
    }
    
    for(int i=n-1; i>=1; i--) {
        for(int money=0; money<=x; money++) {
            
            int val1 = dp[i+1][money];
            int val2 = 0ll;
            
            if(money - price[i] >= 0) {
                val2 = dp[i+1][money - price[i]] + page[i];
            }
            
            if(val1 >= val2) {
                dp[i][money] = val1;
            } else {
                dp[i][money] = val2;
            }
            
        }
    }
    cout << dp[1][x];
        
     
    return 0;
}
