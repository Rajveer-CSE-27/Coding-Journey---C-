/** 
Question : Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.
Approach 1 : Using map to count frequencies of all elements and print all the keys later . -> Time : O(m + n) + map processing time, Space = O(m + n)
Approach 2 : Using set -> Time : O(n + m) + set operation time, Space : O(n + m)
Approach 3 : Using 2 pointers because arrays are sorted -> Time : o(n + m) , Space : O(1)
**/

#include <bits/stdc++.h>
using namespace std;

vector<int> solve1(int n, int m, vector<int>& arr, vector<int>& brr) {
    map<int,int> mp;
    
    for(int i=0; i<n; i++) {
        mp[arr[i]]++;
    }
    for(int j=0; j<m; j++) {
        mp[brr[j]]++;
    }
    
    vector<int> ans;
    for(auto it:mp) {
        ans.push_back(it.first);
    }
    
    return ans;
}

vector<int> solve2(int n, int m, vector<int>& arr, vector<int>& brr) {
    set<int> st;
    
    for(int i=0; i<n; i++) {
        st.insert(arr[i]);
    }
    for(int i=0; i<m; i++) {
        st.insert(brr[i]);
    }
    
    vector<int> ans;
    for(auto it:st) {
        ans.push_back(it);
    }
    
    return ans;
}

void solve3(int n, int m, vector<int>& arr, vector<int>& brr) {
    if(n == 0 && m == 0) {
        return;
    }
    if(n == 0) {
        for(auto it:brr) {
            cout << it << " ";
        }
        return;
    }
    if(m == 0) {
        for(auto it:arr) {
            cout << it << " ";
        }
        return;
    }
    
    int i=0,j=0 , prev;
    if(arr[i] <= brr[j]) {
        prev = arr[i];
        i++;
    } else {
        prev = brr[j];
        j++;
    }
    
    cout << prev << " ";
    
    while(i < n && j < m) {
        if(arr[i] <= brr[j] && arr[i] > prev) {
            prev = arr[i];
            cout << arr[i] << " ";
            i++;
        } else if(arr[i] <= brr[j] && arr[i] <= prev) {
            i++;
        } else if(arr[i] > brr[j] && brr[j] > prev) {
            prev = brr[j];
            cout << brr[j] << " ";
            j++;
        } else {
            j++;
        }
    }
    
    while(i < n) {
        if(arr[i] > prev) {
            prev = arr[i];
            cout << arr[i] << " ";
        }
        i++;
    }
    
    while(j < m) {
        if(brr[j] > prev) {
            prev = brr[j];
            cout << brr[j] << " ";
        }
        j++;
    }
    
}

int main() {
    
    int n,m;
    cin >> n >> m;
    vector<int> arr(n) , brr(m);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<m; i++) {
        cin >> brr[i];
    }
    
    vector<int> ans1 = solve1(n,m,arr,brr);
    for(auto it:ans1) {
        cout << it << " ";
    }
    cout << endl;
    
    vector<int> ans2 = solve2(n,m,arr,brr);
    for(auto it:ans2) {
        cout << it << " ";
    }
    cout << endl;
    
    solve3(n,m,arr,brr);
    
    
    return 0;
}
