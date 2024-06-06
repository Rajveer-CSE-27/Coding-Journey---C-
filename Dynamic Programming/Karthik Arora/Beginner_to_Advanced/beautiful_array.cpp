// || जय जय जय बजरंग बली ||

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

/**
Problem Link :: https://codeforces.com/contest/1155/problem/D

Approach :: These type of problem include popular concept of dp on subarrays.

Any problem with dp on subarrays must be approached by writing dp[i] for each index i where the subarray "ends".
The subarray could start from any index j <= i but dp[i] will only give the value for best subarray that ends at index i.

Here dp[i] will tell us the maximum possible sum of subarray that ends at index i with the conditions given in the question.

Constraints to use the value x :

				at any time :: Either x has been previously used {for a previous subarray} and is not allowed to use now.
							   Either x is being used by subarray starting from index j < i . And now we extend the use of x to current index also.
							   Option to use x is available but we still dont use it.
			
				x -> 0 :: if using x is not available
				x -> 1 :: if using x is available ;; -> 1 if it is currently being used by previous subarray and we extend it to ith index.
													 -> 0 if it is not used at all and we have option to use it from current index i but we are not using it.
							   

let we form dp[n][2][2]

dp[i][0][0] = maximum sum of any subarray that ends at index i such that x was used  for a previous subarray.
dp[i][1][0] = maximum sum of any subarray that ends at index i such that x was not used by any prior subarray and there is an option to use x now.
dp[i][1][1] = maximum sum of any subarray that ends at index i such that x is being used till previous index and there is option to use it for current index.

Base case :: 
dp[0][0][0] = 0; because we are only at 1st index then how come we already used x for a previous subarray. It is not possible hence maximum sum = 0
dp[0][1][0] = vc[i]; we have option to use x but we do not use it
dp[0][1][1] = x*vc[i]; we use x

dp[i][0][0] = vc[i] + max(either we used x till previous index, either we used x before any index other than previous index)
			  vc[i] + max(dp[i-1][1][1], dp[i-1][0][0])

dp[i][0][0] = max(vc[i], dp[i][0][0]); Because there is an option of not using the x. 

dp[i][1][0] = vc[i] + (we also had option to use x at i-1 index but we didnt used it there, hence we still have option to use it here and we still do not use it)
			  vc[i] + dp[i-1][1][0]
				
dp[i][1][0] = max(vc[i], dp[i][1][0])

dp[i][1][1] = x*vc[i] + max(either we had option to use x in previous index and not used it, used x in previous index)
			  x*vc[i] + max(dp[i][1][0], dp[i][1][1])

dp[i][1][1] = max(x*vc[i], dp[i][1][1])


we will return the maximum value of dp[i][j][k] over all possible values of i,j,k
							   

**/

signed main() {
        
    int n,x;
    cin >> n >> x;
    
    vector<int> vc(n);
    for(int i=0; i<n; i++) {
    	cin >> vc[i];
    }
    
    int dp[n][2][2];
    memset(dp, 0, sizeof dp);
    
    dp[0][0][0] = 0;
    dp[0][1][0] = vc[0];
    dp[0][1][1] = x*vc[0];
    
    for(int i=1; i<n; i++) {
    	dp[i][0][0] = vc[i] + max(dp[i-1][0][0], dp[i-1][1][1]);
    	dp[i][0][0] = max(vc[i], dp[i][0][0]);
    	
    	dp[i][1][0] = vc[i] + dp[i-1][1][0];
    	dp[i][1][0] = max(vc[i], dp[i][1][0]);
    	
    	dp[i][1][1] = x*vc[i] + max(dp[i-1][1][1], dp[i-1][1][0]);
    	dp[i][1][1] = max(x*vc[i], dp[i][1][1]);
    }
    
    int ans = 0;
    for(int i=0; i<n; i++) {
    	ans = max({ans, dp[i][0][0], dp[i][1][0], dp[i][1][1]});
    }
    
    cout << ans;
    
    return 0;    
}
