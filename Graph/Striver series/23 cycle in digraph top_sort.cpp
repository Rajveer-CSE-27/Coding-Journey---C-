bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> indegree(V,0);
        for(int i=0; i<V; i++) {
            
            for(int j=0; j<adj[i].size(); j++) {
                indegree[adj[i][j]]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0; i<V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(int next:adj[node]) {
                indegree[next]--;
                if(indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        if(ans.size() == V) {
            return false;
        }
        return true;
    }
