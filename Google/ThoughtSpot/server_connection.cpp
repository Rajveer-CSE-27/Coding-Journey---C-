class Solution {
public:


    int bfs(int node, vector<vector<pair<int,int>>>& tree, int s, int d, int par) {

        queue<vector<int>> q;
        q.push({node, 0, par});


        int cnt = 0;

        while(!q.empty()) {
            vector<int> vc = q.front();
            q.pop();

            if((vc[1] + d)%s == 0) {
                cnt++;
            }

            for(pair<int,int> adj:tree[vc[0]]) {

                if(adj.first != vc[2]) {
                    q.push({adj.first, vc[1] + adj.second, vc[0]});
                }

            }
        }

        return cnt;


    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;

        vector<vector<pair<int,int>>> tree(n);
        for(int i=0; i<n-1; i++) {
            tree[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            tree[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }


        vector<int> ans(n, 0);        

        for(int i=0; i<n; i++) {
            
            vector<int> vc;
            for(pair<int,int> adj:tree[i]) {

                int v = bfs(adj.first, tree, signalSpeed, adj.second, i);
                vc.push_back(v);

            }

            if(!vc.empty()) {
                if(vc.size() > 1) {
                    int sm = 0;
                    for(int x:vc) {
                        sm += x;
                    }
                    int cnt = 0;

                    for(int x:vc) {
                        cnt += ((sm - x)*x);
                    }
                    cnt /= 2;
                    ans[i] = cnt;
                }
            }

        }

        return ans;
    }
};
