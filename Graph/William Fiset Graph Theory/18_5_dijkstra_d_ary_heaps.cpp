// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=pSqmAO-m7Lk&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=18

D-ary heap optimization for Dijkstra :: 
	

	When executing Dijkstra's algorithm, especially on dense graphs, there are a lot more updates (i.e decreasekey operations) to key-value pairs than there are pop/dequeue operations.
	A D-ary heap is a heap variant in which each node has D children. This speeds up decrease key operations at the expense of more costly removals.
	{Till now we were using binary heaps}
	
	Removals are clearly much more expensive, as we would swap root with last node, then do heapify.
	 but they are also a lot less common in Dijkstra's than decreaseKey operations.
	 
	Q-> What is the optimal D-ary heap degree to maximize performance of Dijkstra's algorithm?
	In general D = E/V or m/n is the best degree to use to balance removals against decreaseKey operations.
	improving Dijkstra's time complexity to 0(E*logE/V (V)) {i.e O(ElogD(V)) D is base }, which is much better especially for dense graphs which have lots of decreaseKey operations.
	 
	
	The current state of the art as of now is the Fibonacci heap
	which gives Dijkstra's algorithm a time complexity of O(E + VlogV)
	Fibonacci heaps are very difficult to implement and have a large enough constant amortized overhead to make them impractical unless your graph is quite large.
	 
**/

int main(){
	
    return 0;
}
