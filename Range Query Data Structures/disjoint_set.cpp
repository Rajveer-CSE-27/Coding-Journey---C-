// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=JDycPHW4kIs&list=PLb3g_Z8nEv1isaHPaXL1j-pSo60812JtY&index=5

Disjoint Set Data structure

Sample problem statement :: 
    -> Given undirected graph G(V,E)
    -> Answer Q queries of the form (u,v) where answer is True if a path exists from u to v in graph else False.

Possible solution :: 
    -> Perform 1 BFS/DFS for each node and store all the nodes which are reachable from current node.
    -> Per query answering time :: O(1)
    -> Pre processing time :: O(V*(V + E)) = O(V^3) in case of dense graphs
    -> Overall time complexity :: O(Q + V^3)
    
Using Disjoint set data structure we can optimize this.

Disjoint Set Data Structure :: 
    -> It is a collection of disjoint sets of nodes of the graph.
    -> D = {S1, S2, S3, ...., Sk}
    -> Each node of the graph belongs to exactly one of the sets.
    -> The sets would cover all the nodes in the graph.
    -> Each set Si has set representative Ri.
    
    -> Disjoint set data structure supports various functions :: 
        -> Make_Set(x) :: Creates a new Set with only element x and representative x.
        -> Find(x) :: Returns the representative of the set to which x belongs.
        -> Union(x,y) :: Unites the sets containing the elements x and y into a single new Set. The representative of this set is usually either the representative of Sx or representative of Sy.
    
Using Disjoint Set Data Structure we can solve the given problem ::
    -> Run Make_Set(u) for each node u in the Graph.
    -> Run Union(u,v) for each edge (u,v) in the Graph.
    -> For each query (u,v) :: 
            -> If Find(u) == Find(v) : return true
            -> Else return false.
            
    -> Time Complexity :: 
            O(V * Make_Set) + O(E * Union) + O(Q * Find)
            E can be = O(V^2)
            
Disjoint Set - Forest Implementation 
    -> Think of every set of nodes as a tree.
    -> With root node = Representative node of the set.
    -> See 15:30
    -> Store parent of each node. Parent of root is itself.
    
    Make_Set(u) can be performed in O(1) as create a tree with 1 node whose parent is itself.
    Union(u,v) 
        -> We have 2 trees one which includes u and other which includes v.
        -> Let root nodes be R1 and R2.
        -> Make R2 as a child of R1. i.e parent of R2 = R1.
        -> This will combine everyting required into 1 tree i.e 1 set.
        -> Time to do this :: O(1) because we just need to change 1 pointer.
                
    
    Find(u) 
        -> to find the root node of the tree we need to traverse to the root.
        -> this can lead to O(n) if tree is skew.
        -> Worst case :: O(n) for find(u).
        
        Line 1 :: -> To improve this ::
                We will keep a condition that while performing union always take the Set(tree) with less height and attach it to the set with greater height.
                i.e root node of lesser height tree should become children of root node of greater height tree.
                And we would keep a storage of heights of all trees which can be accessed in O(1).
                
                This will lead to worst case :: O(logn) for find(u).
                
        Line 2 :: -> We can improve it further :: 
            Path compression technique
            See :: 18:00
            
            Jabhi bhi we perform find(u) for any node then at that time first traverse to the root.
            Now change the parent pointer of that node to the actual representative of the node i.e root node of tree.
            By this we make that node as direct children of root and next time find(u) for that same node will require :: O(1) time.
       
        
    Applying both the heuristics at line 1 and 2 together will give us :: 
        
        -> Make_Set(u) = O(1)
        -> Union(u,v) = O(1)
        -> Find(u) = O(alpha(n))
                        Where alpha is the inverse of Ackerman function Ak(1)
                        Alpha(n) <= 4 for all N <= 16^512
                        16^512 >> 10^80
                        
                        Hence for nearly all practical possible use cases alpha(n) <= 4 = O(1)
           
Hence time complexity to solve the sample problem ::
        -> O(V * Make_Set) + O(E * Union) + O(Q * Find)
        -> O(V) + O(E) + O(Q) = O(V) + O(V^2) + O(Q)
        
        -> O(Q + V^2)

Some direct applications of DS :: 
        Finding cycles in a graph
        Kruskals minimum spanning tree algorithm
        
https://www.youtube.com/watch?v=O4w-aX5mSks&list=PLb3g_Z8nEv1isaHPaXL1j-pSo60812JtY&index=6
**/

template <class T>
class DisjointSetDS {
    unordered_map<T, T> parent;
    
    unordered_map<T, pair<int,int>> representative_To_Set_Info;
    // for each representative r it stores {size of the set of r, height of the tree with root = r}

public:
    
    // can add more functionalities as per question demands.
    
    void make_set(T x) {
        // to create a set/tree with single element
        parent[x] = x;
        representative_To_Set_Info[x] = {1,0};
        // initial set size = 1 and initial height of tree = 0
    }
    
    
    T find(T x) {
        // we will also implement path compression which will make every element's {from current node x to root} parent = set representative
        
        if(parent[x] == x) {
            return x;
        }
        
        return parent[x] = find(parent[x]);
    }
    
    void unionSet(T u, T v) { // cannot use union name as it is predefined in C++
        T representative_u = find(u);
        T representative_v = find(v);
        
        if(representative_u == representative_v) {
            return;
        }
        
        // take the Set(tree) with less height and attach it to the set with greater height.
        int height_u = representative_To_Set_Info[representative_u].second;
        int height_v = representative_To_Set_Info[representative_v].second;
        
        if(height_u > height_v) {
            
            // upadate parent of reprsentative_v
            parent[representative_v] = representative_u;
            
            // update size of set of representative_u
            representative_To_Set_Info[representative_u].first += representative_To_Set_Info[representative_v].first;
            
            // note that this will not change the height_u.
            
            // erase representative_v from set of representative nodes
            representative_To_Set_Info.erase(reprsentative_v);
        } else {
            
            parent[representative_u] = reprsentative_v;
            representative_To_Set_Info[representative_v].first += representative_To_Set_Info[representative_u].first;
            
            // only when height_u == height_v then only height_v will increase by 1.
            if(height_u == height_v) {
                representative_To_Set_Info[reprsentative_v].second++;
            }
            
            representative_To_Set_Info.erase(representative_u);
        }
        
    }
};

int main() {
    
    // object of Disjoint set
    //DisjointSetDS<data type> dsu;
    
    
   
    return 0;
}
