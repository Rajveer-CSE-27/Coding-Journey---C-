// Question : You are given an array of integers, your task is to move all the zeros in the array to the end of the array and move non-negative integers to the front by maintaining their order.
// Approach 1 : Make another array and count number of zeroes -> Time : O(n) , Space = O(n)
// Approach 2 : Whenever you get 0 shift all right side element one step left and place 0 at end -> time : O(n^2) , space : O(1)
// Approach 3 : 2 pointers approach . -> time : O(n) , space : O(1)


#include <bits/stdc++.h>
using namespace std;

void approach2(int n, vector<int>& arr) {
    int i = 0, j = arr.size();
        while(i < j) {
            if(arr[i] == 0) {
                for(int k=i+1; k<j; k++) {
                    arr[k-1] = arr[k];
                }
                j--;
                arr[j] = 0;
            } else {
                i++;
            }
        }
}

void approach3(int n, vector<int>& arr) {
    
    // find the first occurence of 0 in array
    int i=0;
    while(i < n) {
        if(arr[i] == 0) {
            break;
        }
        i++;
    }
    
    if(i == n) {
        // array contains no 0
        return;
    }
    
    int j = i+1;
    while(j < n) {
        if(arr[j] != 0) {
            // we will swap with the first occurence of 0
            swap(arr[i],arr[j]);
            i++; // now i points to first occurence of 0
        }
        
        j++;
    }
    
}

int main() {
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        
    }
    approach2(n,arr);
    
    for(auto it:arr) {
        cout << it << " ";
    }
    cout << endl;
    
    approach3(n,arr);
    
    for(auto it:arr) {
        cout << it << " ";
    }
    
    return 0;
}
