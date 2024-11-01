#include <bits/stdc++.h>
using namespace std;

int ans;

void fun(vector<int>& vc, vector<vector<int>>& mat, int& n, int& m, int& k, int x) {
    
    if(x == k) {
        vector<vector<int>> grid;
        grid = mat;
        
        for(int j=0; j<m; j++) {
            if(vc[j]%2 == 1) {
                
                for(int i=0; i<n; i++) {
                    grid[i][j] = mat[i][j]^1;
                }
            }
        }
        
        int cnt = 0;
        for(int i=0; i<n; i++) {
            bool flag = true;
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 0) {
                    flag = false;
                }
            }
            if(flag == true) {
                cnt++;
            }
        }
        ans = max(ans, cnt);
        return;
    }
    
    
    for(int j=0; j<m; j++) {
        vc[j]++;
        fun(vc, mat, n, m, k, x+1);
        vc[j]--;
    }
    
}

int main() {
    
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> mat[i][j];
        }
    }
    
    ans = 0;
    vector<int> vc(m, 0);
    
    fun(vc, mat, n, m, k, 0);
    
    cout << ans;
    
    
    return 0;
}
