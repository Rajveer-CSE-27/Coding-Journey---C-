// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int mx = 1e6;

/**
Problem :: Triangles in a graph 
           Given a graph with 𝑛≤2000 vertices and 𝑚≤𝑛⋅(𝑛−1)/2 edges, count triples of vertices 𝑎,𝑏,𝑐 such that there are edges 𝑎−𝑏, 𝑎−𝑐 and 𝑏−𝑐.
           
           
approach :: use bitset for adjacenecy list representation of each node in graph.
            iterate through all possible pairs of nodes. 
            For each pair : 
                    If there exist an edge between these two nodes then count all the nodes to which both have edge.
                    Update the number of traingles. as this count.
                    
            This method will give 3*real answer. Hence divide ans by 3.
            
            
Time :: O(n*n*t) where t = O(2001/32) or (2001/64).
            
**/


int main() {
    
    int n;
    cin >> n;
    int edges;
    cin >> edges;
    
    bitset<2001> adjacenecy_list[n];
    
    for(int i=0; i<edges; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        adjacenecy_list[n1].set(n2);
        adjacenecy_list[n2].set(n1);
    }
    
    
    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(adjacenecy_list[i][j] == 1) {
                bitset<2001> temp = (adjacenecy_list[i] & adjacenecy_list[j]);
                ans += temp.count();
            }
        }
    }
    
    cout << ans/3;
    
    return 0;
    
}
