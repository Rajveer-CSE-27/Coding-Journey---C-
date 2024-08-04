// || जय जय जय बजरंग बली ||

#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=KiCBXu4P-2Y&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=6
https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

Graph theory on grids :: 
	A common approach to solving graph theory problems on grids is to first convert the grid to a
	familiar format such as an adjacency list/matrix.
	
	But rather than converting it to a graph, we can traverse it in same way as graph and use all properties of graph accordingly.
	
	Direction vectors :: 	
				This makes it very easy to access neighbouring cells from the current row-column position:
				# Define the direction vectors for north, south, east and west.
				dirx[4] = {1,-1,0,0}
				diry[4] = {0,0,1,-1}
				Can also create of size = 8
				
				for (i = 0; i < 4; i++):
					rr = r + dirx[i]
					cc = c + diry[i]
					# Skip invalid cells. Assume R and C for the number of rows and columns 
					if(rr < 0 or rr >= R or cc < 0 or cc >= C) {
						continue
					}
					
	Sample problem :: https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

	Approach :: Can treat grid as graph and problem turns out to be shortest path in unweighted graph. Hence BFS approach.
	

NOTE :: 
	An alternative way to represent multidimensional grid coordinates is to use multiple queues instead of complex structures.
	Just keep in mind that push and pop will be done on all the queues at once whenever push, pop is called.
**/

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        int dirx[4] = {1,-1,0,0};
        int diry[4] = {0,0,1,-1};
        // incase you can move in 8 directions, then make dirx[8] and diry[8]
        
        
        queue<pair<int,int>> q;
        q.push(source);
        vis[source.first][source.second] = true;
        
        if(source.first == destination.first and source.second == destination.second) {
        	// edge case 1
            return 0;
        }
        
        if(grid[source.first][source.second] == 0 or grid[destination.first][destination.second] == 0) {
        	// edge case 2
            return -1;
        }
        
        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                pair<int,int> node = q.front();
                q.pop();
                
                for(int k=0; k<4; k++) {
                    int x = node.first + dirx[k];
                    int y = node.second + diry[k];
                    
                    if(x == destination.first and y == destination.second) {
                        if(grid[x][y] == 1) {
                            return level+1; // becuase iska level tabtak update nhi hua hoga
                        }
                        return -1;
                    }
                    
                    if(x >= 0 and x < n and y >= 0 and y < m and grid[x][y] == 1) {
                        if(vis[x][y] == false) {
                            vis[x][y] = true;
                            q.push({x,y});
                        }
                    }
                }
                
            }
            level++;
        }
        
        return -1;
        
    }
};

int main() {
	
	
	
	return 0;
}
