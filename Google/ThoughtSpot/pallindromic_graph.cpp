class Solution {
public:

    map<int,int> mp; // keep track of path

    void dfs(int node, vector<vector<pair<int,char>>>& tree, int mask) {


        mp[mask]++; // ye humesha yahi likhna

        for(pair<int,char> adj:tree[node]) {
            int d = (adj.second - 'a'); // ye iss step pe aake karna

            int nextMask = (mask^(1<<d));
            dfs(adj.first, tree, nextMask);
        }

    }

    long long countPalindromePaths(vector<int>& parent, string s) {
        

        int n = parent.size();
        vector<vector<pair<int,char>>> tree(n);

        for(int i=1; i<n; i++) {
            tree[parent[i]].push_back({i, s[i]});
        }

        dfs(0,tree,0);


        long long ans = 0ll;

        // pairs with even length pallindrome
        for(auto it:mp) {
            long long val = it.second;
            ans += (val*(val - 1));
        }

        // pairs with odd length pallindrome
        for(auto it:mp) {
            int key = it.first;
            long long val = it.second;

            // 1 bit must differ 
            for(int j=0; j<26; j++) {

                int req = (key ^ (1<<j));
                if(mp.find(req) != mp.end()) {
                    ans += (val * mp[req]);
                }
            }

        }

        return ans/2;

    }
};
