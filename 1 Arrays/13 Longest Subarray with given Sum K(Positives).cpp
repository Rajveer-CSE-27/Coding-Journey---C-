/** Question : Given an array and a sum k, we need to print the length of the longest subarray that sums to k.
    Approach 1 :: 2 loops approach and find all the subarrays. Time : O(n^2) , Space : O(1)
    Approach 2 :: Hashing approach, Time : O(n) , Space : O(n)
    Approach 3 :: 2 pointers approach , Time : O(2*n) , Space : O(1)
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

int approach3(int n, int k, int arr[]) {
    
    int l=0, r=0;
    int sm = arr[0];
    int ans = 0;
    while(r < n) {
        
        while(l <= r && sm > k) {
            sm -= arr[l];
            l++;
        }
        if(sm == k) {
            ans = max(ans, r-l+1);
        }
        
        r++;
        if(r<n) sm += arr[r];
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
    
    int ans3 = approach3(n,k,arr);
    cout << ans3 << endl;
    
    return 0;
}    
