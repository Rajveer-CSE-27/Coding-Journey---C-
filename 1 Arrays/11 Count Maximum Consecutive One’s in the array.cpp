/** 
Question : Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.
Approach 1 : 1 iteration only. See code you will understand. -> Time : O(n) , Space : O(1)
**/

#include <bits/stdc++.h>
using namespace std;

int solve(int n, int nums[]) {
    int mx = 0 , cnt=0;
        for(int i=0; i<n; i++) {
            if(nums[i] == 1) {
                cnt++;
            } else {
                if(cnt > mx) {
                    mx = cnt;
                    
                }
                cnt = 0;
            }
        }
        if(cnt > mx) {
            mx = cnt;
                    
        }
        return mx;
}

int main() {
    
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    int ans = solve(n, arr);
    cout << ans << endl;
    
    
    return 0;
}
