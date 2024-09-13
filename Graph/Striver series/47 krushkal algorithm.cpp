// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**

https://leetcode.com/problems/min-cost-to-connect-all-points/?envType=problem-list-v2&envId=minimum-spanning-tree
https://www.youtube.com/watch?v=DMnDM_sxVig&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=47

Krushkal algo

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
            representative_To_Set_Info.erase(representative_v);
        } else {
            
            parent[representative_u] = representative_v;
            representative_To_Set_Info[representative_v].first += representative_To_Set_Info[representative_u].first;
            
            // only when height_u == height_v then only height_v will increase by 1.
            if(height_u == height_v) {
                representative_To_Set_Info[representative_v].second++;
            }
            
            representative_To_Set_Info.erase(representative_u);
        }
        
    }
};


class Solution {
public:

    static bool comp(pair<int, pair<int,int>> p1, pair<int, pair<int,int>> p2) {
        return (p1.first < p2.first);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        DisjointSetDS<int> dsu;
        int n = points.size();

        for(int i=0; i<n; i++) {
            dsu.make_set(i);
        }

        vector<pair<int,pair<int,int>>> edges;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dis, {i,j}});
            }
        }
        sort(edges.begin(), edges.end(), comp);

        int ans = 0;
        for(int i=0; i<edges.size(); i++) {
            int w = edges[i].first, n1 = edges[i].second.first, n2 = edges[i].second.second;

            if(dsu.find(n1) != dsu.find(n2)) {
                ans += w;
                dsu.unionSet(n1, n2);
            }
        }

        return ans;
    }
};


int main() {
   
   
    return 0;
}
