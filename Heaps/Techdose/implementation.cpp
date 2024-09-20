// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=cuL8gXCSA58&list=PLEJXowNB4kPyP2PdMhOUlTY6GrRIITx28&index=4
https://www.youtube.com/watch?v=VkKmmwzfIG4&list=PLEJXowNB4kPyP2PdMhOUlTY6GrRIITx28&index=6

Heaps :: 
     Binary heaps are implemented with concepts of complete binary tree {perfect till last level and last level starts filling from right to left}.
     There could be n-ary heaps also.
     
     Max-heap :: Complete binary tree in which root is always maximum and same is followed by all sub-trees.
     Min-heap :: Complete binary tree in which root is always minimum and same is followed by all sub-trees.
     
    
Storing a heap :: 
    A complete binary tree can be represented in the form of an array.
    Parent -> i
    Left child -> 2*i + 1
    Right child -> 2*i + 2
    
    i starts from 0.
    
    If child is at index : i then parent is at index [ceil(i/2) - 1]
    
    If height of tree is h then maximum elements it can store is :: 2^(h+1) - 1
    Hence that should be the size of the array.
    
    
    Range of leaves = floor(n/2) + 1 to n  if we used 1 based indexing.
                      for 0 based :: floor(n/2) to n-1 
    Hence range of internal nodes :: 0 to floor(n/2) - 1
    

Note :: sorted array will be minheap always
        sorted array in reverse order will be maxheap always.
        
Heapify :: 
    The process of rearranging the heap by comparing each parent with it's children recursively is called heapify.
    
    Goal of a heapify on an index i is that :: 
                Given all children (subtree starting at child nodes) of i are valid heaps, then convert the subtree with root at i as valid heap.
                
    Let if you want to perform max-heapify :: 
    
        Get the largest child.
        If arr[largest child] <= arr[index] then subtree with root at index is already a valid max-heap
        Else swap them and call heapify(arr, largest)
    
        Go on recursively doing this till you reach a leaf node.
        Note :: a single node is always a valid heap.
        
    
    Time :: O(logn) i.e O(h) because in complete tree h is always logn

Build heap :: 
    
    We know that leaf nodes are already heaps.
    If we convert all the internal subtrees as valid heap then our whole tree will be a valid heap.
    
    For a subtree to call heapify on it, we need that all it's children must be a valid heap.
    Hence we must go in reverse order of internal nodes one by one and convert them into a valid heap.
    
    Hence call heapify for all internal nodes in reverse order and you will convert your tree into a valid heap.
    
    Time :: O(n)
    
    Proof :: 
             Time complexity to heapify a node with height h = O(h)
             Maximum number of nodes that have height h in a complete binary tree = ceil(n / 2^(h+1))
             
             Total work done at level h = ceil(n / 2^(h+1)) * O(h)
             
             
             Total time for all levels = x
                                        
                                        x = 0
                                        for(h = 0 to h = logn) {
                                            x += ceil(n / 2^(h+1)) * O(h)
                                        }
                                        
                            hence x = (c*n)/2 * sum(h/2^h)  = {sum(h/2^h) = 2 for h=0 to inf}
                            hence x = c*n/2 * 2 = c*n = O(n)
                        
                            
    
**/

void minHeapify(vector<int>& arr, int index, int& n) {
    // given that all children of index are valid min-heaps, we need to make subtree with root as index a valid heap

    int left = 2*index + 1;
    int right = 2*index + 2;
    
    int smallest = index;
    
    if(left < n and arr[left] < arr[smallest]) {
        smallest = left;
    }
    if(right < n and arr[right] < arr[smallest]) {
        smallest = right;
    }
    
    if(smallest == index) {
        return;
    }
    
    swap(arr[index], arr[smallest]);
    minHeapify(arr, smallest, n);
}

vector<int> build_min_heap(vector<int> vc, int n) {
    
    vector<int> arr = vc;
    
    // call the minHeapify for all internal nodes in reverse order
    for (int i = n-1; i >= 0; i--) {
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (l < n or r < n) { // internal node
            minHeapify(arr, i, n);
        }
    }
    
    return arr;
}

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
    
    vector<int> mnHeap = build_min_heap(vc,n);
    vector<int> mxHeap = build_max_heap(vc,n);
    
    return 0;
}
