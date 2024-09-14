// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=Rn6B-Q4SNyA&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=51
https://www.geeksforgeeks.org/problems/number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-islands

DSU
**/

template <class T>
class DisjointSetDS {
    unordered_map<T, T> parent;
    unordered_map<T, pair<int,int>> representative_to_Set_info; // {size, height}

public:
    
    void make_set(T x) {
        parent[x] = x;
        representative_to_Set_info[x] = {1,0};
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
        
        int height_u = representative_to_Set_info[representative_u].second;
        int height_v = representative_to_Set_info[representative_v].second;
        
        if(representative_v == representative_u) {
            return;
        }
        
        if(height_u > height_v) {
            parent[representative_v] = representative_u;
            representative_to_Set_info[representative_u].first += representative_to_Set_info[representative_v].first;
            representative_to_Set_info.erase(representative_v);
        } else {
            parent[representative_u] = representative_v;
            representative_to_Set_info[representative_v].first += representative_to_Set_info[representative_u].first;
            representative_to_Set_info.erase(representative_u);
            
            if(height_u == height_v) {
                representative_to_Set_info[representative_v].second++;
            }
            
        }
    }
    
    int components() {
        return representative_to_Set_info.size();
    }
    
    
};

class Solution {
  public:
  
    inline int val(int i, int j, int m) {
        int ans = i + j + (m-1)*i;
        return ans;
    }
  
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // DSU
        
        // representing each cell(i,j) with a unique number
        vector<int> ans;
        DisjointSetDS<int> dsu;
        
        vector<vector<bool>> taken(n, vector<bool>(m, false));
        
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        
        for(vector<int> vc:operators) {
            int i = vc[0], j = vc[1];
            int num = val(i,j,m);
            
            if(taken[i][j] == false) {
                taken[i][j] = true;
                
                dsu.make_set(num);
                for(int k=0; k<4; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if(x >= 0 and y >= 0 and x < n and y < m and taken[x][y] == true) {
                        int num2 = val(x,y,m);
                        dsu.unionSet(num, num2);
                    }
                }
            }
            
            ans.push_back(dsu.components());
            
        }
        
        return ans;
        
    }
};




int main() {
   
   
    return 0;
}
