// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long


/**
https://www.youtube.com/watch?v=GhjwOiJ4SqU&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=35
https://www.youtube.com/watch?v=ar6x7dHfGHA&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=36

Bipartite graph :: 
    2 colourable
    No odd length cycles
    A Bipartite Graph is a graph whose vertices can be partitioned into two disjoint sets U and V such that every edge can only connect a vertex in U to a vertex in V.    
    
    
Maximum Cardinality matching :: 
    Fundamental problem in graph theory, where goal is to find a matching{set of edges} which contains maximum number of edges 
    such that each vertex in the graph is adjacent to atmost 1 edge from the matching.
    As each edge covers 2 vertices, the problem converts to task to find a matching which covers as many vertices as possible.
    
    Special case of this problem is when graph is bipartite. In this case the problem can be solved with simpler algorithms.
    MCM is then called MCBM where B stands for bipartite.

    -> If graph is Bipartite and edges are unweighted :: 
            Solved by any of these :: 
                -> Max flow algo
                -> Repeatedly augmenting path with DFS
                -> Kuhn's Algorithm
                -> Hopcroft-Karp algorithm
                
	-> If graph is Bipartite and edges are  weighted :: 
            Try ::
                -> Min cost max flow algorithm
                -> Hungarian algorithm (perfect matching)
                -> LP network simplex
    
    -> If graph is not Bipartite and edges are unweighted :: 
                Edmond's blossom algorithm
                
    -> If graph is not Bipartite and edges are weighted ::   
                DP on small graphs
                
 
Currently we will only focus on 1st varitation. Bipartite + unweighted.

Lemma :: A matching M is maximum  =  there is no augmenting path left to the matching M .


See first video from 4:20 for explaining how we solve MCM for bipartite + unweighted with max flow.
In this example we can calculate maximum number of people that can be get a book.
Also we can check maximum number of books that can be assigned to a person.

    ->We set the capacity for each edge from source to all person = 1. 
                This means that each person can get atmost 1 book.
                If for an edge between source and person we increase it's capacity to k, then this would mean that person can get atmost k books.
                hence that person can be matched with atmost k books.
    
    -> We set the capacity for each edge from Book to sink = 1.
                This means that each book can be selected by atmost 1 person only.
                If for an edge between source and person we increase it's capacity to k, then this would mean that a book can be assigned to atmost k people at a time.
                Hence k copies of that book would exists in the network.
        
    
    -> we set the capcity for each edge from a person to a book = 1.
                This means that a person is allowed to get atmost 1 copy of that book at a time.
                If for an edge between source and person we increase it's capacity to k, then this would mean that a person can have atmost k copies of that book at a time.
    
    By making one , more or none of these changes we can solve multiple problems.
    
    
We can get maxflow by any of the maxflow algorithms and that will be our MCBM here.
WHEN YOU GET THE CODE OF EFFICIENT ALGORITHMS TO GET MAX FLOW THEN PASTE IT.
CURRENTLY WE ARE USING FORG-FULKERSON ALGORITHM FOR MAX FLOW.


Video 2 : Mice and Owls problem

Try to convert the given problem into MCBM.

    One set of vertices for Mouse and other set of vertices for holes.
    First compute which mouse can go into which holes and connect them by an edge of capacity = 1. Becuase a mouse can use that hole only once.
    Create a source node and connect to all mouses with capacity = 1 because each mouse can go into atmost 1 holes.
    Create a sink node and connect all holes to that sink node with capacity = 1 becuase each hole can be used by atmost 1 mouse only.
    
    Now run max_flow algorithm.
    MCBM on this graph will give us how many mouses can find a hole or how many holes can be filled.
    This is the required answer.

**/


int main (){
    
    
}
