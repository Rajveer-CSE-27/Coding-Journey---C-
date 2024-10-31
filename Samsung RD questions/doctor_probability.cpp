#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

void dfs(int node, vector<vector<pair<int, double>>>& graph, int time, vector<double>& vc, double prob) {
  
  if(time <= 0) {
    // this node will have doctor at end
    // probabily of this path from start node 1 = prob
    vc[node] += prob;
    
    // adding because we can have a different path that could end here.
    return;
  }
  
  
  for(pair<int,double> adj:graph[node]) { 
    dfs(adj.first, graph, time - 10.0, vc, prob * adj.second);
  }
  
  // NOTE :: we assumed that doctor starts to travel from start node at t = 0
  
  
}

void solve() {
  int n,m, time;
  cin >> n >> m >> time;
  
  vector<vector<pair<int, double>>> graph(n+1); // directed
  for(int i=0; i<m; i++) {
    int n1,n2;
    double p;
    cin >> n1 >> n2;
    cin >> p;
    
    graph[n1].push_back({n2, p});
  }
  
  // we need to find the position of doctor after time minutes which has the highest probability of having doctor. Also print the probability
  // if no such positions found, output 0 and 0.0
  
  vector<double> vc(n+1, 0.0);
  // vc[i] will represent probability of doctor after time at node i
  
  
  // start node = 1;
  dfs(1, graph, time, vc, 1.0);
  
  
  int pos = 0;
  double maxProb = 0.0;
  
  for(int i=1; i<=n; i++) {
    if(vc[i] > maxProb) {
      maxProb = vc[i];
      pos = i;
    }
  }
  
  
  cout << pos << " " << fixed << setprecision(10) << maxProb;
  
}

int main() {
  
  int tc;
  cin >> tc;
  while(tc--) {
    solve();
    cout << '\n';
  }
  
  return 0;
  
}
