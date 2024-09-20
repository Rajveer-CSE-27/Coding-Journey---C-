// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=kU4KBD4NFtw&list=PLEJXowNB4kPyP2PdMhOUlTY6GrRIITx28&index=7
https://www.geeksforgeeks.org/problems/heap-sort/1

Heap sort 
    Time :: O(nlogn)
    Space :: O(logn)
    
Appraoch :: 
    Let us use min heap.
    Extract the min element (i.e get min element and delete it )
    Repeat above step for all elements
    
    Time :: O(n * logn)
       
     
**/

void minHeapify(vector<int>& mnHeap, int n, int i) {
    // min heapify function
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
      
    if(l < n and mnHeap[l] < mnHeap[smallest]) {
        smallest = l;
    }
      
    if(r < n and mnHeap[r] < mnHeap[smallest]) {
        smallest = r;
    }
      
    if(smallest == i) {
        return;
    }
    
    swap(mnHeap[smallest],mnHeap[i]);
    minHeapify(mnHeap,n,smallest);
} 

int extractMin(vector<int>& mnHeap, int n) {
    
    if(n == 0) {
        cout << "Heap underflow\n";
        return -1;
    }
    
    int ans = mnHeap[0];
    mnHeap[0] = mnHeap[n-1];
    
    mnHeap.pop_back();
    
    minHeapify(mnHeap, n-1, 0);
    
    return ans;
    
}

vector<int> build_min_heap(vector<int> vc, int n) {
    // building min heap
    
    vector<int> mnHeap = vc;
    for(int i=n-1; i>=0; i--) {
        int l = 2*i + 1;
        int r = 2*i + 2;
            
        if(l < n or r < n) { // internal node
            minHeapify(mnHeap, n, i);
        }
    }
    
    return mnHeap;
}


int main() {
   
    int n;
    cin >> n;
    vector<int> vc(n);
    for(int i=0; i<n; i++) {
        cin >> vc[i];
    }
    
    vector<int> mnHeap = build_min_heap(vc,n);
     
    
    int sz = n;
    for(int i=0; i<n; i++) {
        int val = extractMin(mnHeap, sz);
        sz--;
        cout << val << " ";
    }
        
        
    return 0;
}
