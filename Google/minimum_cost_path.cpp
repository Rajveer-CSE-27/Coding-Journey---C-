#include <bits/stdc++.h>
using namespace std;
#define int long long

/**
Minimum cost path
You are given an integer matrix A that has N rows and M columns. The rows are numbered from 1 to N
from top to down and the columns are numbered from 1 to M from left to right.
You have to find a path from the first column to the last column of the matrix. There is a cost attached to a
path. This cost is defined as the absolute difference between the maximum and minimum elements visited
along the path. For example, if the path you have chosen is P i , P2, P s . . Pm. then cost of this path will be as
f o l l o w s :
cost = maxP) - min(P). Here, maxP) is the maximum element on the path P and min(P) is the
minimum element on the path P.
You are required to find a path that has the minimum cost from the first column to the last column of the
matrix. While you can start from any row number, you must start from the first column. You can also e n d at
any row but you must end at the last column.
Your task is to reach the Mth column from 1st column. If you are in the i , j cell, then you can move to any
cell in the j+ 1)th column.


1<=T<=10
1<=N,M<=500
0<=Ai<=10^9

Approach :: 

For each cell 𝐴𝑖𝑗, generate a pair (𝐴𝑖𝑗,𝑗).
Now sort these pairs in ascending order. Let's denote 𝑓𝑖 as the first value of the 𝑖th pair, and 𝑠𝑖 as the second value of the 𝑖th pair (when sorted).
(edit: why do I need to do this to get a new paragraph :/) The problem is equivalent to finding the segment [𝑙,𝑟]
with minimum 𝑓𝑟−𝑓𝑙 such that the set of values 𝑠𝑙,𝑠𝑙+1,...,𝑠𝑟 contain every single element from 1 to 𝑀. This can be solved via 2 pointers in 𝑂(𝑁𝑀).
**/

void solve() {
  
  int n,m;
  cin >> n >> m;
  
  vector<vector<int>> matrix(n, vector<int>(m));
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> matrix[i][j];
    }
  }
  
  
  vector<pair<int,int>> vc;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      vc.push_back({matrix[i][j], j});
    }
  }
  
  sort(vc.begin(), vc.end());
  
  int i=0, j=0;
  int k = vc.size();
  
  map<int,int> cols;
  
  while(cols.size() < m) {
    
    cols[vc[j].second]++;
    
    j++;
  }
  
  int res = vc[j-1].first - vc[i].first;
  
  
  while(j < k) {
    
    cols[vc[i].second]--;
    if(cols[vc[i].second] == 0) {
      cols.erase(vc[i].second);
    }
    i++;
    
    while(j < k and cols.size() < m) {
      cols[vc[j].second]++;
      j++;
    }
    
    if(cols.size() == m) {
      int temp = vc[j-1].first - vc[i].first;
      res = min(res, temp);
    }
    
  } 
  
  cout << res;
  
  
}


signed main() {
  
  int tc;
  cin >> tc;
  
  while(tc--) {
    solve();
    cout << '\n';
  }
  
  return 0;
  
}
