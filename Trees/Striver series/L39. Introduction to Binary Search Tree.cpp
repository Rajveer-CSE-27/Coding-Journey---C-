// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=p7-9UvDQZ3w&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=39

Theory :: 
	BST = binary search tree.
	For any node : 
			-> Its left subtree is a valid BST
			-> Its right subtree is a valid BST
			-> left node val < current node val < right node val.
	
	Note that ideally :: l < curr < r
	But if we want to handle duplicates then we can do it in 3 ways ::
			-> l <= curr < r
			-> l < curr <= r
			instead of just a value at the node store : {val, freq}
			Now there will be unique nodes each having {val,freq} and these nodes could represent a BST.
	
	On average the height of BST = O(logn).
	We try to fix the root node in such a way that height of BST = O(logn)
	
	
	NOTE:: It is not necessary that height is always = O(logn)
		   It could be = O(n) that is skew. But in majority cases it is O(logn).
**/


int main() {
    
   
    
    return 0;
}
