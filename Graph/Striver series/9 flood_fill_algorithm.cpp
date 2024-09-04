// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=C-2_uSRli8o&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=9
https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm

DFS
Move in 4 directions.

Time :: O(n*m)
Space :: O(1)
                          
**/

class Solution {
public:  
    
    int dirx[4] = {0,0,1,-1};
    int diry[4] = {1,-1,0,0};
    
    void dfs(int i, int j, int& color, int& newColor, vector<vector<int>>& image, int& n, int& m) {
        
        image[i][j] = newColor;
        for(int k=0; k<4; k++) {
            int x = i + dirx[k], y = j + diry[k];
            
            if(x < n and y < m and x >= 0 and y >=0 and image[x][y] == color) {
                dfs(x,y,color,newColor,image,n,m);
            }
        }
        
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        int n = image.size(), m = image[0].size();
        
        if(color == newColor) {
            return image;
            // as this will lead to infinite looping
        }
        
        dfs(sr,sc,color,newColor,image,n,m);
        
        return image;
    }
};


int main() {
       
    return 0;
}
