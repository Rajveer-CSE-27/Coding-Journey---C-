// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=KkeIB6soiVI&list=PLEJXowNB4kPyP2PdMhOUlTY6GrRIITx28&index=6

Here only considering max-heaps.

Build max heap :: O(n).

Find max :: O(1) 
        First element will always be max element
    
Extract max element :: O(logn)
        Copy the last element to first element. 
        Delete the last element from array.
        Heapify the root node. This will take O(logn) time.

Insert :: O(logn)
        Insert an element to last position of the array.
        Let index = last element index.
        
        Recursively go on checking whether arr[index] > arr[parent_of_index]
                    If yes :: swap(arr[index], arr[parent_of_index])
                    Else :: STOP
                    
        Time :: O(h) = O(logn)

Increase key :: O(logn) :: increase the value at at specific node in array
        
        Let index = the index of element increased
        Recursively go on checking whether arr[index] > arr[parent_of_index]
                    If yes :: swap(arr[index], arr[parent_of_index])
                    Else :: STOP
                    
        Time :: O(h) = O(logn)
        
Decrease key :: O(logn) :: decrease the value at at specific node in array
        Let index = the index of element decreased
        
        Hepafiy the given index.
        Time :: O(h) = O(logn)
    
Find Min :: O(n) :: search the entire leaf nodes.

Search random element :: O(n) :: search the entire array

Delete random element :: O(n)
            Searching element :: O(n) 
            Deleting it :: O(logn)

        
**/

void maxHeapify(vector<int>& arr, int index, int& n) {
    // given that all children of index are valid max-heaps, we need to make subtree with root as index a valid heap
    
    int left = 2*index + 1;
    int right = 2*index + 2;
    
    int largest = index;
    
    if(left < n and arr[left] > arr[largest]) {
        largest = left;
    }
    if(right < n and arr[right] > arr[largest]) {
        largest = right;
    }
    
    if(largest == index) {
        return;
    }
    
    swap(arr[index], arr[largest]);
    maxHeapify(arr, largest, n);
    
}


int find_max(vector<int>& mxHeap, int n) {
    // O(1)
    
    if(n == 0) {
        
        cout << "Heap underflow\n";
        return -1;
    }
    
    return mxHeap[0];
}


int extract_max(vector<int>& mxHeap, int n) {
    // O(logn)
    
    if(n == 0) {
        cout << "Heap underflow\n";
        return;
    }
    
    int mx = mxHeap[0];
    mxHeap[0] = mxHeap[n-1]; // copy last element to first position
    
    mxHeap.pop_back();
    maxHeapify(mxHeap, 0, n-1); // now there are total n-1 elements in heap only
    
    return mx;
}

void insert_element(vector<int>& mxHeap, int n, int element) {
    // O(logn)
    
    mxHeap.push_back(element);
    n++;
    
    // go upwards till you can swap or reach the root node
    
    int index = n - 1;
    
    while(index > 0) {
        int parent = ceil((double)index/2) - 1;
        
        if(mxHeap[index] > mxHeap[parent]) {
            swap(mxHeap[index], mxHeap[parent]);
            index = parent;
        } else {
            break;
        }
    }
    
}

void increase_key(vector<int>& mxHeap, int n, int key, int val) {
    
    // O(logn)
    
    if(index >= n or index < 0) {
        cout << "INVALID KEY INDEX\n";
        return;
    }
    
    mxHeap[key] += val;
    
    // go upwards till you can swap or reach the root node
    int index = key;
    while(index > 0) {
        int parent = ceil((double)index/2) - 1;
        
        if(mxHeap[index] > mxHeap[parent]) {
            swap(mxHeap[index], mxHeap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void decrease_key(vector<int>& mxHeap, int n, int key, int val) {
    // O(logn)
    
    if(index >= n or index < 0) {
        cout << "INVALID KEY INDEX\n";
        return;
    }
    
    mxHeap[key] -= val;
    
    // call heapify on key
    maxHeapify(mxHeap, key, n);
}

int find_min(vector<int>& mxHeap, int n) {
    
    // O(n)
    
    // search through all leaf nodes.
    
    int ans = INT_MAX;
    
    for(int i=n-1; i>=0; i--) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        
        if(l >= n and r >= n) { // this is a leaf node
            ans = min(ans, mxHeap[i]);
        }
    }
    
    return ans;
}


int search_element(vector<int>& mxHeap, int n, int element) {
    // O(n)
    
    for(int i=0; i<n; i++) {
        if(mxHeap[i] == element) {
            return i;
        }
    }
    return -1;
}

void delete_element(vector<int>& mxHeap, int n, int index) {
    // O(logn)
    
    if(index >= n or index < 0) {
        cout << "INVALID KEY INDEX\n";
        return;
    }
    
    // swap with last and delete the last
    swap(mxHeap[index], mxHeap[n-1]);
    mx.pop_back();
    
    maxHeapify(mxHeap, index, n-1);
}

vector<int> build_max_heap(vector<int> vc, int n) {
    
    vector<int> arr = vc;
    
    // call the maxHeapify for all internal nodes in reverse order
    for (int i = n-1; i >= 0; i--) {
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (l < n or r < n) { // internal node
            maxHeapify(arr, i, n);
        }
    }
    
    return arr;
}

int main() {
   
    int n;
    cin >> n;
    vector<int> vc(n);
    for(int i=0; i<n; i++) {
        cin >> vc[i];
    }
    
    vector<int> mxHeap = build_max_heap(vc,n);
        
    
        
    return 0;
}
