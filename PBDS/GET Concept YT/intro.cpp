// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
Policy based data structure (PBDS)

-> Used as ordered set.
-> It has all the functionalities of regular set with same time complexity (insert, find, upper_bound, etc).. Also it has 2 additional things.

Madatory things need to write in code :: 

    #include<ext/pb_ds/assoc_container.hpp>
    #include<ext/pb_ds/tree_policy.hpp>
    
    using namespace __gnu_pbds;
    
    typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
    
    // that is itni badi cheez ki jagah oset likh do
    // when using :: oset o; o.insert(1), ...
    // insert time :: O(logn)
    
Explaination of these things :: 
    
    This has 5 parameters :: 
    
        1. int :: it represents the data type. You can change it to double, string, pair<int,char>, vector<int>, etc as per your convenience.
        
        2. null_type :: this tells that the given data structure is ordered set
        
        3. less<int> :: comparator and inside there is <data type>
                -> less<data type> : stores unique elements stored in ascending order. Duplicate value daalne pe oset ka size nhi badhega.
                -> less_equal<data type> :: stores non unique elements in ascending order. Duplicate value daalne pe oset ka size badhega.
                -> greater<data type> :: stores unique elements stored in descending order. Duplicate value daalne pe oset ka size nhi badhega.
                -> greater_equal<data type> :: stores non unique elements stored in descending order. Duplicate value daalne pe oset ka size badhega.
        
        4. rb_tree_tag :: this tells that it is implemented using red black tree
        
        5. tree_order_statistics _node_update :: helps to access functionalities of trees.


find_by_order(k) ::
    
    this function gives the address of element which is stored at kth index. (0 based indexing)
    Time :: O(logn)
    
    oset o;
    o.find_by_order(k) gives address of element present at index k.
    *o.find_by_order(k) will give value.
    
    if k >= n then find_key_order(k) will give garbage value.
    
order_of_key(x) ::
    
    Time :: O(logn)
    comparator type versus result of order_of_key(x) :: {x is a value, it may or may not be part of oset}
        
        less<> :: it will give number of elements strictly smaller than x.
        less_equal<> :: it will give number of elements strictly smaller than x.
        greater<> :: it will give number of elements strictly greater than x.
        greate_equal<> :: it will give number of elements strictly greater than x.
    
deleting an element from ordered set :: 
    
    int index = o.order_of_key(x)
    auto it = o.find_by_order(index)
    o.erase(it)
    
    Time :: O(logn + logn + logn) = O(logn)
**/




int main() {
    
    oset o;
    o.insert(11);
    o.insert(24);
    o.insert(51);
    o.insert(101);
    o.insert(11);
    
    for(auto e:o) {
        cout << e << " ";
    }
    cout << '\n';
    
    cout << *o.find_by_order(1) << '\n';
    
    cout << o.order_of_key(50) << '\n';
    
    int index = o.order_of_key(24);
    auto it = o.find_by_order(index);
    o.erase(it);
    
    for(auto e:o) {
        cout << e << " ";
    }
    
    return 0;
}
