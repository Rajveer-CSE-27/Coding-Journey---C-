/**
Binary tries
https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
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


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie trie;
        for(int i=0; i<n; i++) {
            trie.insert(nums[i]);
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            int temp = trie.findMaxXor(nums[i]);
            ans = max(ans, temp);
        }
        return ans;
    }
};
