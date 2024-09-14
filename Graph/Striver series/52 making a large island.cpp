// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=lgiz0Oup6gM&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=52
https://leetcode.com/problems/making-a-large-island/

DSU
**/

template <class T>
class DisjointSetDS {
public:
    
    unordered_map<T, T> parent;
    unordered_map<T, pair<int,int>> representative_to_set_info;

    void make_set(T x) {
        parent[x] = x;
        representative_to_set_info[x] = {1,0};
    }
    
    T find(T x) {
        
        if(parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    
    void unionSet(T u, T v) {
        T representative_u = find(u);
        T representative_v = find(v);
        
        if(representative_v == representative_u) {
            return;
        }
        
        int height_u = representative_to_set_info[representative_u].second;
        int height_v = representative_to_set_info[representative_v].second;
        
        if(height_u > height_v) {
            parent[representative_v] = representative_u;
            representative_to_set_info[representative_u].first += representative_to_set_info[representative_v].first;
            representative_to_set_info.erase(representative_v);
            
        } else {
            parent[representative_u] = representative_v;
            representative_to_set_info[representative_v].first += representative_to_set_info[representative_u].first;
            representative_to_set_info.erase(representative_u);
            
            if(height_u == height_v) {
                representative_to_set_info[representative_v].second++;
            }
            
        }
    }
    
    int sz(T r) {
        return representative_to_set_info[r].first;
    }
    
};
class Solution {
public:

    inline int val(int i, int j, int m) {
        int ans = i + j + (m-1)*i;
        return ans;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        DisjointSetDS<int> dsu;
        
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    int num = val(i,j,m);
                    dsu.make_set(num);
                } 
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                if(grid[i][j] == 1) {
                    ans = max(ans, 1);
                    int num = val(i,j,m);
                    
                    for(int k=0; k<4; k++) {
                        int x = i + dx[k], y = j + dy[k];
                        
                        if(x >= 0 and y >= 0 and x < n and y < m and grid[x][y] == 1) {
                            int num2 = val(x,y,m);
                            dsu.unionSet(num, num2);
                            int rep = dsu.find(num2);
                            int temp = dsu.sz(rep);
                            
                            ans = max(ans, temp);
                        }
                    }
                    
                } 
            }
        }
        
       
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 0) {
                    
                    set<int> st;
                    for(int k=0; k<4; k++) {
                        int x = i + dx[k], y = j + dy[k];
                        
                        if(x >= 0 and y >= 0 and x < n and y < m and grid[x][y] == 1) {
                            int num2 = val(x,y,m);
                            int repr = dsu.find(num2);
                            st.insert(repr);
                        }
                    }
                    
                    int temp = 1;
                    for(auto it:st) {
                        temp += dsu.sz(it);
                    }
                    ans = max(ans, temp);
                }
            }
        }
        
        
        return ans;
    }
};








int main() {
   
   
    return 0;
}
