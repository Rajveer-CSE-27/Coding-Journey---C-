//https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

class Solution{

  public:
  
  
    int fun(int i, int sm, int arr[], int& n, vector<vector<int>>& dp, int& x) {
        if(i == n) {
            int temp = x - sm;
            int val = abs(temp - sm);
            return val;
        }
        
        if(dp[i][sm] != -1) {
            return dp[i][sm];
        }
        
        // take
        int v1 = fun(i+1, sm + arr[i], arr, n, dp, x);
        int v2 = fun(i+1, sm, arr, n, dp, x);
        
        return dp[i][sm] = min(v1, v2);
    }
  
  
	int minDifference(int arr[], int n)  { 
	    int sm = 0;
	    for(int i=0; i<n; i++) {
	        sm += arr[i];
	    }
	    
	    vector<vector<int>> dp(n, vector<int>(sm + 1, -1));
	    int ans = fun(0, 0, arr, n, dp, sm);
	    
	    return ans;
	} 
};

