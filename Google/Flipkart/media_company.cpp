#include <bits/stdc++.h>
using namespace std;
#define ll long long

 
class Solution {
public:

    vector<vector<int>> graph;
    vector<int> indegree;
    vector<int> outdegree;


    void dfs(int node, vector<int>& eulerPath) {
        while(outdegree[node] != 0) {
            outdegree[node]--;
        int nextNode = graph[node][outdegree[node]];
        dfs(nextNode, eulerPath);
        }
        eulerPath.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,int> mp;
        int n = 0;
        for(vector<string> vc:tickets) {
            string s = vc[0], t = vc[1];
            if(mp.find(s) == mp.end()) {
                mp[s] = n;
                n++;
            }
            if(mp.find(t) == mp.end()) {
                mp[t] = n;
                n++;
            }
        }
        int cnt = 0;
        for(auto it:mp) {
            mp[it.first] = cnt; // this will help to store in sorted order first
            cnt++;
        }

        vector<string> city(n);
        for(auto it:mp) {
            city[it.second] = it.first;
        }

        graph.resize(n);
        indegree.resize(n,0);
        outdegree.resize(n,0);

        for(vector<string> vc:tickets) {
            int n1 = mp[vc[0]], n2 = mp[vc[1]];
            graph[n1].push_back(n2);
            outdegree[n1]++;
            indegree[n2]++;
        }

        for(int i=0; i<n; i++) {
            sort(graph[i].rbegin(), graph[i].rend()); // to keep lexicographic order first. Also we gonna reverse at end so sorting in descending order
        }

        // given that a valid eulerian path exists
        int start = mp["ABC"];
        vector<int> eulerPath;
        dfs(start, eulerPath);

        reverse(eulerPath.begin(), eulerPath.end());

        vector<string> ans;
        for(int i=0; i<eulerPath.size(); i++) {
            ans.push_back(city[eulerPath[i]]);
        }
        return ans;
    }
};
