/** Question : Given an array and a sum k, we need to print the length of the longest subarray that sums to k.
    Approach 1 :: 2 loops approach and find all the subarrays. Time : O(n^2) , Space : O(1)
    Approach 2 :: Hashing approach, Time : O(n) , Space : O(n)
    2 pointers will not work here as numbers are negative also
**/

#include <bits/stdc++.h>
using namespace std;

int approach1(int n, int k, int arr[]) {
    int ans = -1;
    for(int i=0; i<n; i++) {
        int sm = 0;
        for(int j=i; j<n; j++) {
            sm += arr[j];
            if(sm == k) {
                ans = max(ans,j-i+1);
            }
        }
    }
    return ans;
}

int approach2(int n, int k, int arr[]) {
    // Hashing.
    // Prefix Sum karo usko hash table me daalo and search karo ki prefixSum[i] + k element hai ki nahi.
    // Prefix sum me max index store karo taaki max size subarray hum nikal sake
    
    map<int,int> prefixSum;
    int sm = 0;
    for(int i=0; i<n; i++) {
        sm += arr[i];
        prefixSum[sm] = i;
    }
    int ans = -1;
    for(int i=0; i<n; i++) {
        if(prefixSum.find(arr[i] + k) != prefixSum.end()) {
            ans = max(ans,prefixSum[arr[i]+k] - i);
        }
    }
    
    return ans;
}


int main() {
    int n = 7, k = 3;
    int arr[] = {1,2,-3,0,3,1,2};
    
    int ans1 = approach1(n,k,arr);
    cout << ans1 << endl;
    
    int ans2 = approach2(n,k,arr);
    cout << ans2 << endl;
    
    
    return 0;
}    
