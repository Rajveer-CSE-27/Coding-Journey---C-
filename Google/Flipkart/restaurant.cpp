#include <bits/stdc++.h>
using namespace std;
#define ll long long

void fun(int node, vector<vector<int>>& tree, vector<int>& inorder) {
  
  int m = tree[node].size();
  
  if(m > 0) {
    fun(tree[node][0], tree, inorder);
  }
  
  inorder.push_back(node);
  
  if(m > 1) {
    fun(tree[node][1], tree, inorder);
  }
  
} 

int main() {
  
  int n;
  cin >> n;
  vector<int> vc(n);
  for(int i=0; i<n; i++) {
    cin >> vc[i];
  }
  
  int row,col;
  cin >> row >> col;
  
  vector<vector<int>> tree(n);
  
  for(int i=0; i<n-1; i++) {
    int n1,n2;
    cin >> n1 >> n2;
    tree[n1].push_back(n2);
  }
  
  int m;
  cin >> m;
  
  vector<int> inorder;
  fun(0, tree, inorder);
  
  
  cout << vc[inorder[m - 1]] << '\n';
  for(auto it:inorder) {
    cout << it << " ";
  }
  
  return 0;
}
