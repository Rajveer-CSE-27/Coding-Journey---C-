// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define int long long

/**
https://www.youtube.com/watch?v=-dUiRtJ8ot0&list=PLgUwDviBIf0rf5CQf_HFt35_cF04d8dHN&index=4

Segment tree :: 
    It is used for solving range query problems.
    Especially when we have update queries.
    
    See the video.
    With the help of segment tree method we can perform :: 
            Update query in O(logn) time.
            Answer query in O(logn) time.
            
    We store the segment tree as an array of size 4*n
    Becuause size of segment tree <= 4*n
    
    For any node at index i it's children will be at :: 
            Left child :: 2*i + 1
            Right child :: 2*i + 2
            
    The leaf nodes of the segment tree will have the elements of the array itsels.
    
    Every node of the tree will store result of an operation (sum, max, min, gcd, etc) applied on array elements between range :: [l,r]
    
    must see video
    

For update queries :: 
    We will update in O(logn) time
    
https://cses.fi/problemset/result/10367385/

**/

// int a[MAX_N], segTree[4 * MAX_N];
int a[2 * 100005], segTree[8 * 100005];

void build(int index, int low, int high) {

    
    // index will represent the index of segTree node
    // low, high represents the range [l,r] that this node gives result for i.e operation applied on array elements from l to r
    
    if(low == high) {
        // base case 
        // this will store array element
        segTree[index] = a[low];
        return;
    }
    
    int mid = (low + high)/2;
    
    build(2*index + 1, low, mid); // left child
    build(2*index + 2, mid + 1, high); // right child
    
    // here we are using min as operation
    segTree[index] = min(segTree[2*index + 1], segTree[2*index + 2]);
    // if you wanted some other operation then update code here.
}

int query(int index, int low, int high, int l, int r) {
    // this will give result of query from range [l,r]
    // low, high represents the range [l',r'] that this node gives result for i.e operation applied on array elements from l' to r'
    // l,r represents the range [l',r'] that we want answer for
    
    if(low >= l and high <= r) {
        // then value reprsented by this segTree node is of range [l',r'] while lies whole inside our required range [l,r]
        // hence use this whole
        return segTree[index];
    }
    
    if(high < l or low > r) {
        // then this range is of no use to us. As no element of this range intersects with our required range
        return INT_MAX;
        //because this is a min operation we return INT_MAX
        // if this was sum operation the we would return 0
        // and so on.....
    }
    
    
    // now we have range [low,high] in which some elements are required and some are not
    int mid = (low + high)/2;
    int leftValue = query(2*index + 1, low, mid, l, r);
    int rightValue = query(2*index + 2, mid + 1, high, l, r);
    
    return min(leftValue, rightValue);
}

void rangeUpdate(int index, int low, int high, int l, int r, int val) {
    
    if(high < l or low > r) {
        // OUT OF RANGE
        return;
    }
    
    if(low == high) {
        // base case
        segTree[index] = val;
        return;
    }
    
    // else for any case we will go to it's left child and right child for propagating the update
    int mid = (low + high)/2;
    
    rangeUpdate(2*index + 1, low, mid, l, r, val);
    rangeUpdate(2*index + 2, mid + 1, high, l, r, val);
    
    segTree[index] = min(segTree[2*index + 1], segTree[2*index + 2]);
    
}

signed main() {
    
    int n,q;
    cin >> n >> q;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    build(0, 0, n-1);
    // O(n) time to build
    
    
    
    while(q--) {
        int type, x, u;
        cin >> type >> x >> u;
        
        if(type == 1) {
            
            // val me exact value daalo
            a[x-1] = u;
            rangeUpdate(0, 0, n-1, x-1, x-1, u);
            
        } else {
            int ans = query(0,0,n-1, x-1, u-1);
            cout << ans << '\n';
        }
    }
    
    return 0;
}
