// || जय जय जय बजरंग बली ||

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**
Problem Link :: https://medium.com/@sonakshisaxena1/problem-analysis-of-kickstart-round-c-4e547f1ce7b5
Catch Some Problem	
see karthik arora video for explaination

Approach :: dp approach

    Observation :: 
        1. You must use a color only once to get best results. That is it will make poor results if you use same color for multiple iterations.
        2. While using each color you will 
                        either make 2 iterations till the required dog for all colors except 1.
                        or will make 1 iteration to the required dog for 1 remaining color.
        
        3. Order of iteration does not matter . Jab bhi 1 color ka 1 iteration karna hai kar sakte ho.
    
    dp[i][j][k] = Best time such that current color is = i and you still need to count j dogs. 
                 k is boolean that is == 0 if you have not made that 1 single iteration.
                                      == 1 else.

			   

**/

vector<int> dog_color[1001];
int dp[1001][1001][2];

int fun(int color, int dogs_left, bool single_color_iteration_status) {
    
    if(color == 1001) {
        return 1e9;
    }
    if(dogs_left <= 0) {
        return 0;
    }
    
    if(dp[color][dogs_left][single_color_iteration_status] != -1) {
        return dp[color][dogs_left][single_color_iteration_status];
    }
    
    int ans = INT_MAX;
    
    if(single_color_iteration_status == true) {
        
        for(int i=0; i<dog_color[color].size(); i++) {
            int val = 2 * dog_color[color][i] + fun(color+1, dogs_left - i, true);
            ans = min(ans, val);
        }
        
    } else {
        
        for(int i=0; i<dog_color[color].size(); i++) {
            int val1 = 2 * dog_color[color][i] + fun(color+1, dogs_left - i, false);
            int val2 = dog_color[color][i] + fun(color+1, dogs_left - i, true);
            ans = min({ans, val2, val1});
        }
    }
    
    return dp[color][dogs_left][single_color_iteration_status] = ans;
    
}

void solve() {    
    int n,k;
    cin >> n >> k;
    
    vector<int> pos(n), color(n);
    for(int i=0; i<n; i++) {
        cin >> pos[i];
    }
    for(int i=0; i<n; i++) {
        cin >> color[i];
    }
    
    for(int i=0; i<=1000; i++) {
        dog_color[i].clear();
    }
    memset(dp, -1, sizeof dp);
    
    for(int i=0; i<=1000; i++) {
        dog_color[i].push_back(0);
    }
    
    for(int i=0; i<n; i++) {
        dog_color[color[i]].push_back(pos[i]);
    }
    
    // NOTE : sorting is very important.
    for(int i=0; i<=1000; i++) {
        sort(dog_color[i].begin(), dog_color[i].end());
    }
    
    int ans = fun(1,k,false);
    cout << ans << '\n';
    
}

int main() {
    
    int tc;
    cin >> tc;
    
    while(tc--) {
        solve();
        cout << '\n';
    }
    
    return 0;    
}
