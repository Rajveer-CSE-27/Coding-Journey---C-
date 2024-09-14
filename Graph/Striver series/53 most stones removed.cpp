// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=OwMNX8SPavM&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=53
https://www.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-stone-removal

DSU
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
    
    int components() {
        return representative_To_Set_Info.size();
    }
};

class Solution {
  public:
  
    
  
    int maxRemove(vector<vector<int>>& stones, int n) {
        // DSU
        
        // answer is total stones -number of components after all possible merging
        
        map<int, vector<int>> row, col;
        DisjointSetDS<int> dsu;
        
        for(int i=0; i<n; i++) {
            row[stones[i][0]].push_back(i);
            col[stones[i][1]].push_back(i);
            
            dsu.make_set(i);
        }
        
        for(auto it:row) {
            vector<int> vc = it.second;
            int u = vc[0];
            for(int i=1; i<vc.size(); i++) {
                dsu.unionSet(u, vc[i]);
            }
        }
        
        for(auto it:col) {
            vector<int> vc = it.second;
            int u = vc[0];
            for(int i=1; i<vc.size(); i++) {
                dsu.unionSet(u, vc[i]);
            }
        }
        
        int sz = dsu.components();
        return n - sz;
        
        
        
    }
};




int main() {
   
   
    return 0;
}
