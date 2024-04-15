#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Problem link :: https://cses.fi/problemset/task/1639/
Approach :: 
        
        Focus that we can only do 3 types of tasks.
        Let we construct dp matrix of [n][m]
        
        dp[i][j] = minimum cost required such that we equilize the ith element of first string and jth element of the second string.
        
        Let we are at the ith element of first string and jth element of the second.
        Now if :: s1[i] == s2[j] then dp[i][j] = dp[i+1][j+1].
            else :: there are 3 cases :: 
                            1. If we add the element in s1 at this position which is equal to s2[j].
                                        i.e s1i, s1i+1, s1i+2, ...... s1n           adding character before s1i => s2j, s1i, s1i+1, s1i+2, ...... s1n
                                                                                                                   s2j, s2j+1, s2j+2,............s2m       
                                            s2j, s2j+1, s2j+2,............s2m  
                                    
                                    hence this will make dp[i][j] = 1 + dp[i][j+1] // because now we have to make s1i and s2j+1 equal.
                                                                    // we added 1 becuase this operation costs 1
                            
                            2. If we remove the element from front of s1 then ::
                                        dp[i][j] = 1 + dp[i+1][j]
                                
                            3. Replace s1i with s2j.
                                        dp[i][j] = 1 + dp[i+1][j+1]
                
                the dp[i][j] will take minimum of all the 3 values.
        
        
        Base case :: If one or both of the string finishes then we need to delete all the remaining elements/ characters of the other string.
                        Hence this will cost = remaining length of the other string.
                                            

**/

int dp[5001][5001];

int solve(int i, int j, string& s1, string& s2) {
    
    if(i == s1.length() or j == s2.length()) { // base case
        // hence either of them have reached end and answer = remaining characters in another string
        int ans = max(s1.length() - i, s2.length() - j);
        return ans;
    }
    
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    
    int ans;
    if(s1[i] == s2[j]) {
        ans = solve(i+1, j+1, s1, s2);
    } else {
        
        // we can add at s1
        int ans1 = 1 + solve(i, j+1, s1, s2);
        
        // we can remove at s1
        int ans2 = 1 + solve(i+1, j, s1, s2);
        
        // we can replace at s1 with value at s2
        int ans3 = 1 + solve(i+1, j+1, s1, s2);
        
        ans = min({ans1, ans2, ans3});
    }
    
    return dp[i][j] = ans;
    
}

int main() {
    
    string s1, s2;
    cin >> s1 >> s2;
    
    memset(dp, -1, sizeof dp);
    
    int ans = solve(0,0,s1,s2);
    cout << ans;
     
    return 0;
}
