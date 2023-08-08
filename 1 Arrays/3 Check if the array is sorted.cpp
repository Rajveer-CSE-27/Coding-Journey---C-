// Question : Leetcode 1752
// Approach : Find the pivot from where array is rotated. And then start from that point till array size and check the sorted property.
// Time complexity ; O(N) , Space Complexity :: O(1)

#include <bits/stdc++.h>
using namespace std;

bool solve(int n, vector<int>& nums) {
    
    int i=0;
    while(i < nums.size()-1) 
    {
        if(nums[i] <= nums[i+1]) {
            i++;
        } else {
            break;
        }
    }

    if(i == nums.size()-1) {
        return true;
        // array already sorted
    }

    i += 1; // now i will point to the pivot index
    // this is our first element of sorted array hence we iterate the array from here and check sorted property
    int k = 1;
    while(k != nums.size()) {
        if(nums[i%nums.size()] <= nums[(i+1)%nums.size()]) {
            i++;
            k++;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        
    }
    
    bool ans = solve(n, arr);
    if(ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
