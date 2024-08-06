// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=-_Jj4U5V4N0&list=PLb3g_Z8nEv1isaHPaXL1j-pSo60812JtY&index=4

Prefix arrays :: 
	
	If you have an array : {a1,a2,a3,.........}
	And you need to answer q queries of type :: [l,r] that is an operation performed for :: {al,al+1,......,ar}
	Then it is good to use prefix arrays.

	1. Prefix sum array :: solving Range sum queries
		P[i] will store sum of elements from a1 to ai
		Hence if we want sum from [l,r] = P[r] - P[l-1]
		
	2. Prefix xor array :: solving Range xor queries
		P[i] will store xor of elements from a1 to ai
		Hence if we want xor from [l,r] = P[r]^P[l-1]
	
	3. Prefix product array :: solving Range product queries
		P[i] will store product of elements from a1 to ai
		Hence if we want product from [l,r] = P[r]/P[l-1].
		
		NOTE :: here any ai != 0. Then only prefix product will work.
		
	So total time complexity :: O(n + q)
			 space complexity :: O(n)
			 
	
	Note :: Range min will not work here. Because 
				For sum :: sm(x,y) = r. Now from r we can identify y if x is given
				For xor :: xr(x,y) = r. Now from r we can identify y if x is given
				For product(x,y) = r. Now from r we can identify y if x is given and both r,x != 0
				
				But for min(x,y) = r, from r and x (given that x <= y) we can never identify y.
				Hence with prefix arrays we cannot solve range min queries
**/

int main(){
	
	
	
    return 0;
}
