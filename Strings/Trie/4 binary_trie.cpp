// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**

https://www.youtube.com/watch?v=EIhAwfHubE8&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=7

Binary trie :: 
    
    Instead of character you take binary values i.e 0,1 and make a trie based on that.
    Helps in efficient storage of multiple numbers. 
    Helps to perform bit operations on multiple numbers very fast.
    
    You must keep the number of bits of all the numbers you store in the trie same.
    Generally it's 32 bits, but if numbers are large then use 64 bits.
    
Problem Statement :: 
    Given an array of numbers and a value x.
    Find the maximum value of :: (arr[i] xor x).
    
Approach :: 
    Store the array numbers in form of Trie.
    You must store the bits from LHS.
    
    We store the bits of each number from LHS as while computing maximum xor we focus to find a number similar to (x' where all bits of x are toggled).
    Hence comparing from LHS bits will help us to find elements that best increment the overall xor value.
    Because :: 2^i > 2^(i-1) + 2^(i-2) + ..... + 2^1 + 2^0
    
    
    
Time complexity :: O(n) to build trie + O(32) to compare and get answer
**/


struct TrieNode {
    
    // here we do not need flag node. If your question demands then keep it
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

    // if you are using bitset then #include <bitset>
public:
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int n) {
        bitset<32> b(n);
        
        TrieNode* temp = root;
        
        for(int i=31; i>=0; i--) { // start filling from LHS
            int index;
            (b.test(i)) ? index = 1 : index = 0;
            
            if(temp->contains(index) == false) {
                temp->add(index);
            }
            
            temp = temp->getNextTrieNode(index);
        }
        
    }
    
    int find_max_xor(int x) {
        
        bitset<32> b(x);
        
        int ans = 0;
        
        TrieNode* temp = root;
        for(int i=31; i>=0; i--) { // start checking from RHS
            int index;
            (b.test(i)) ? index = 0 : index = 1;
            // here we want max xor. Hence we will toggle the bits of x and check whether it exists in trie;
            
            if(temp->contains(index) == true) {
                ans += (1<<i); // add 2^i to answer;
                temp = temp->getNextTrieNode(index);
            } else {
                // else go with the available index i.e the other one.
                // atleast 1 index would always be available in any path of the trie because we considered 32 bits for all numbers.
                temp = temp->getNextTrieNode(index^1);
            }
        }
        
        return ans;
        
    }
};


int main() {
    
    
    
    int n;
    cin >> n;
    vector<int> vc(n);
    for(int i=0; i<n; i++) {
        cin >> vc[i];
    }  
    
    
    int x;
    cin >> x;
    
    Trie trie;
    for(int i=0; i<n; i++) {
        trie.insert(vc[i]);
    }
    
    int ans = trie.find_max_xor(x);
    cout << ans;
    
    
    return 0;
}
