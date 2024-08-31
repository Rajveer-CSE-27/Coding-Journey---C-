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
    https://www.youtube.com/watch?v=rwXVCELcrqU&list=PLgUwDviBIf0rf5CQf_HFt35_cF04d8dHN&index=4
    
    We use a method called lazy propogation.
    i.e propagate previous update to the nodes in segTree only when we query it.
    Else keep on storing the update and do not propogate to children.
    
    Whenever we reach a node in segTree during answer query. Perform the stored updates at this node.
    And propagate to immediate child only.
    Ans so on...
    
    Hence time complexity of update is : O(logn)
  
  
https://cses.fi/problemset/task/1648  
 
**/
 
// int a[MAX_N], segTree[4 * MAX_N], lazy[4 * MAX_N];
int a[2 * 100005], segTree[8 * 100005], lazy[8 * 100005];
 
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
    
    // here we are using sum as operation
    segTree[index] = segTree[2*index + 1] + segTree[2*index + 2];
    // if you wanted some other operation then update code here.
}
 
/** BASICS OF HOW TO QUERY IN SEG TREE
 
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
        return 0;
        //because this is a sum operation we return 0
        // if this was max operation the we would return INT_MIN.
        // and so on.....
    }
    
    
    // now we have range [low,high] in which some elements are required and some are not
    int mid = (low + high)/2;
    int leftValue = query(2*index + 1, low, mid, l, r);
    int rightValue = query(2*index + 2, mid + 1, high, l, r);
    
    return (leftValue + rightValue);
}
 
**/
 
void rangeUpdate(int index, int low, int high, int l, int r, int val) {
    
    // meaning of index, low, high, l, r are explained in above function
    
    if(lazy[index] != 0) {
        // there is an update at current index
        segTree[index] += (high - low + 1)*lazy[index];
        
        // as we are dealing with sum queries hence we change the segTree value
        // RHS value indicates that lazy[index] will propogate to all children of index in future and hence value of all will increment
        
        if(low != high) {
            // then propogate this update to immediate children
            lazy[2*index + 1] += lazy[index];
            lazy[2*index + 2] += lazy[index];
        }
        
        lazy[index] = 0;
        // all updates of current index has been performed
    }
    
    // NOTE we didn't returned from previous block becuase we just updated it's value. And our main purpose still remains
    
    if(r < low or l > high or low > high) {
        return;
    }
    
    if(low >= l and high <= r) {
        // then our required range is completely inside current range hence update here only
        
        segTree[index] += (high - low + 1) * val;
        
        // now this val is an update for all children of index. Hence propogate to it's immediate children
        if(low != high) {
            lazy[2*index + 1] += val;
            lazy[2*index + 2] += val;
        }
        
        return;
    }
    
    // if we are outside of the range then
    int mid = (low + high)/2;
    rangeUpdate(2*index + 1, low, mid, l, r, val);
    rangeUpdate(2*index + 2, mid + 1, high, l, r, val);
    
    // becuase this is a sum query hence add left and right result for current result
    segTree[index] = segTree[2*index + 1] + segTree[2*index + 2];
    
}
 
int querySumLazy(int index, int low, int high, int l, int r) {
    
    // this gives sum from range [l,r] of original array
    
    // if there is an update at current index , perform it
    if(lazy[index] != 0) {
        // there is an update at current index
        segTree[index] += (high - low + 1)*lazy[index];
        
        // as we are dealing with sum queries hence we change the segTree value
        // RHS value indicates that lazy[index] will propogate to all children of index in future and hence value of all will increment
        
        if(low != high) {
            // then propogate this update to immediate children
            lazy[2*index + 1] += lazy[index];
            lazy[2*index + 2] += lazy[index];
        } 
        
        lazy[index] = 0;
        // all updates of current index has been performed
    }
    
    if(r < low or l > high or low > high) {
        // value not in range
        return 0;
        // if we were performing max query then we would return INT_MIN here.
    }
    
    if(low >= l and high <= r) {
        return segTree[index];
    }
    
    int mid = (low + high)/2;
    
    int leftValidSm = querySumLazy(2*index + 1, low, mid, l, r);
    int rightValidSm = querySumLazy(2*index + 2, mid + 1, high, l, r);
    
    return (leftValidSm + rightValidSm);
}
 
 
 
signed main() {
    
    int n,q;
    cin >> n >> q;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    build(0, 0, n-1);
    
    // lazy[i] represents the amount by which we need to increase segTree[i] value.
    // no matter what the type of operation is. Lazy[i] will be same.
    memset(lazy, 0ll, sizeof(lazy));
    
    
    while(q--) {
        int type, x, u;
        cin >> type >> x >> u;
        
        if(type == 1) {
            
            // val me difference daalo u - a[index]
            int diff = u - a[x-1];
            a[x-1] = u;
            rangeUpdate(0, 0, n-1, x-1, x-1, diff);
            
        } else {
            int ans = querySumLazy(0,0,n-1, x-1, u-1);
            cout << ans << '\n';
        }
    }
    
    return 0;
}
