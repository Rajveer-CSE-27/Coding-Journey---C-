#include <bits/stdc++.h>
using namespace std;
#define int long long
/**
Problem link :: https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/D
 
Approach :: 
    Looks like Min(Max()) problem using Binary Search.
    Let there be a variable x which tells the maximum edge value in a valid path from 1 to n.
    That is for a given x there exist a valid path from 1 to n with atmost d edges and value of each edge will be <= x.
    
    So the variable x will form a bad-good sequence :: 00000000011111111111.....
    And we need to find the minimal x which is good. Hence let us apply binary search.
        
**/

vector<vector<pair<int,int>>> graph;
int n,m,d;
bool visited[100010];

bool is_good(int mxLimit) {
    vector<bool> tempVisited(n+1, false);
    queue<int> q;
    int level = 0, sz = 1;
    q.push(1);
    
    bool flag = false;
    while(!q.empty()) {
        sz--;
        int node = q.front();
        q.pop();
        
        if(node == n) {
            flag = true;
            break;
        }
        
        for(int i=0; i<graph[node].size(); i++) {
            int nextNode = graph[node][i].first;
            int w = graph[node][i].second;
            
            if(tempVisited[nextNode] == false and w <= mxLimit) {
                q.push(nextNode);
                tempVisited[nextNode] = true;
            }
        }
        if(sz == 0) {//we processed all nodes at one level
            sz = q.size();
            level++;
        }
    }
    
    if(flag == false) {
        return false;
    }
    
    if(level <= d) {
        return true;
    }
    return false;
}

vector<int> path;

bool dfs(int node, int level, int mxLimit) {
    if(level > d) {
        return false;
    }
    if(node == n) {
        return true;
    }
    
    for(int i=0; i<graph[node].size(); i++) {
        int nextNode = graph[node][i].first;
        int w = graph[node][i].second;
        
        if(visited[nextNode] == false and w <= mxLimit) {
            if(dfs(nextNode, level+1, mxLimit) == true) {
                path.push_back(nextNode);
                return true;
            } else if(node == 1) { // we explored one full branch of dfs and didnt found a solution
                path.clear();
                memset(visited, 0, sizeof(visited));
            }
        }
    }
    return false;
}

signed main() {
    cin >> n >> m >> d;
    
    graph.resize(n+1, vector<pair<int,int>>());
    for(int i=0; i<m; i++) {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;
        graph[n1].push_back({n2,w});
    }
    
    int low = 0, high = 1e9 + 100;
    
    while(low + 1 < high) {
        int mid = (low + high)/2;
        if(is_good(mid) == true) {
            high = mid;
        } else {
            low = mid;
        }
    }
    
    if(high == 1e9 + 100) {
        cout << -1;
    } else {
        memset(visited, 0, sizeof(visited));
        dfs(1, 0, high);
        cout << path.size() << '\n';
        
        cout << 1 << " ";
        for(int i=path.size()-1; i>=0; i--) {
            cout << path[i] << " ";
        }
    }
    
}
