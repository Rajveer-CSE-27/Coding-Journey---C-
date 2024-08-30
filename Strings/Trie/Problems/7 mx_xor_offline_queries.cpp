// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=Q8LhG9Pi5KM&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=7
https://www.naukri.com/code360/problems/max-xor-queries_1382020?leftPanelTabValue=PROBLEM

Binary trie but with offline query concept.
v.v imp 
**/

struct TrieNode {
    TrieNode* arr[2] = {NULL};

    bool contains(int i) {
        return (arr[i] != NULL);
    }
    void add(int i) {
        arr[i] = new TrieNode();
    }
    TrieNode* getNextTrieNode(int i) {
        return arr[i];
    }
};

class Trie {
    TrieNode* root;
public:

    Trie() {
        root = new TrieNode();
    }
    void insert(int n) {
        bitset<32> b(n);

        TrieNode* temp = root;
        for(int i=31; i>=0; i--) {
            int index;
            (b.test(i)) ? index = 1 : index = 0;

            if(temp->contains(index) == false) {
                temp->add(index);
            }
            temp = temp->getNextTrieNode(index);
        }
    }

    int findMaxXor(int x) {
        bitset<32> b(x);
        TrieNode* temp = root;

        int ans = 0;
        for(int i=31; i>=0; i--) {
            int index;
            (b.test(i)) ? index = 0 : index = 1;

            if(temp->contains(index) == true) {
                ans += (1<<i);
                temp = temp->getNextTrieNode(index);
            } else {
                temp = temp->getNextTrieNode(index^1);
            }
        }

        return ans;
    }


};

bool comp(pair<pair<int,int>, int> p1, pair<pair<int,int>, int> p2) {

    return (p1.first.second <= p2.first.second);
}

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    Trie trie;
    sort(arr.begin(), arr.end());

    // solve the queries in offline fashion
    // adding only the elements in trie whom we know that any query will have >= that number
    
    vector<pair<pair<int,int>, int>> vc(queries.size());
    for(int i=0; i<queries.size(); i++) {
        vc[i] = {{queries[i][0], queries[i][1]}, i};
        }

    sort(vc.begin(), vc.end(), comp);

    vector<int> ans(vc.size());

    int j = 0;
    bool flag = false;

    for(int i=0; i<vc.size(); i++) {
        int mx = vc[i].first.second;
        while(j < arr.size() and arr[j] <= mx) {
            trie.insert(arr[j]);
            flag = true;
            j++;
        }

        int mxXor = -1;
        if(flag == true) {
            mxXor = trie.findMaxXor(vc[i].first.first);
        }
        ans[vc[i].second] = mxXor;
    }

    return ans;

}
