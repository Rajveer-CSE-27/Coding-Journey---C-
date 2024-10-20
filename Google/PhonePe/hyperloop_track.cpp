#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**

Given a directed graph with weighted edges.
Find the minimum cost of converting the graph into a SCC.
You can only reverse the edges.
It is given that there are exactly n edges.

It is guaranteed that there always exist a conversion.


**/

int main() {
  
  
  int n;
  cin >> n;
  vector<map<int,int>> graph(n+1);
  vector<vector<int>> undirected_graph(n+1);
  
  
  for(int i=0; i<n; i++) {
    int n1,n2,w;
    cin >> n1 >> n2 >> w;
    
    graph[n1][n2]  = w;
    graph[n2][n1]  = -w; // ye pata lagane kaam aega ki ye edge exist nhi karta tha
    
    undirected_graph[n1].push_back(n2);
    undirected_graph[n2].push_back(n1);
  }
 
  // Because it is given that there are only n edges, hence you need to find minimum cost of forming a cycle.
  // you can form cycle in 2 ways. Either clockwise or anticlockwise.
  // Hence find minimum cost among both.
  
  
  // First finding cycle through undirected graph
  vector<bool> vis(n+1, false);
  vis[1] = true;
  vector<int> cycle;
  cycle.push_back(1);
  
  int next = undirected_graph[1][0];
  
  while(next != 1) {
    vis[next] = true;
    cycle.push_back(next);
    
    bool flag = false;
    
    for(int adj:undirected_graph[next]) {
      if(vis[adj] == false) {
        next = adj;
        flag = true;
      }
    }
    
    if(flag == false) {
      break;
    }
  }
  
  
  int cost = 0;
  // going from left to right in cycle
  for(int i=0; i<n-1; i++) {
    if(graph[cycle[i]][cycle[i+1]] < 0) {
      cost += abs(graph[cycle[i]][cycle[i+1]]);
    }
  }
  // n >= 3 given in question
  if(graph[cycle[n-1]][cycle[0]] < 0) {
    cost += abs(graph[cycle[n-1]][cycle[0]]);
  }
  
  int cost2 = 0;
  // going from right to left in cycle
  
  for(int i=n-1; i>0; i--) {
    if(graph[cycle[i]][cycle[i-1]] < 0) {
      cost2 += abs(graph[cycle[i]][cycle[i-1]]);
    } 
  }
  
  if(graph[cycle[0]][cycle[n-1]] < 0) {
    cost2 += abs(graph[cycle[0]][cycle[n-1]]);
  }
  
  
  cout << min(cost, cost2);
  
  return 0;
  
}
