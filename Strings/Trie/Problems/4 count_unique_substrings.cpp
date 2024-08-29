// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=RV0QeTyHZxo&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=4
https://www.naukri.com/code360/problems/count-distinct-substrings_985292?leftPanelTabValue=PROBLEM
   
Better ways exists to count unique subtrings.
Here we are doing for the sake of understanding Tries.

This is a space efficient solution as trie helps us to save space.
Iterate over all substrings and add it to trie.

If our trie observes a word for first time then we increment count of unique substring.

In worst case when all substrings are unique trie will also end up storing all the substrings. Which is bad
**/

struct TrieNode {
    
    bool flag = false;
    /** if(flag == true) then this TrieNode marks the end of a valid word. 
        if(flag == false) otherwise
    **/
    
    TrieNode* arr[26] = {NULL};
    /**
        This array contains pointers of type TrieNode
        arr[i] represents the pointer to the next TrieNode if you are currently at ith character in current TrieNode.
    **/
    
    // these functions are added when we implement insert
    bool contains(int i) {
        return (arr[i] != NULL);
    }
    
    void add(int i) {
        arr[i] = new TrieNode();
    }
    
    TrieNode* getNextTrieNode(int i) {
        return arr[i];
    }
    
    void markTrue() {
        flag = true;
    }
};

class Trie {
    
    TrieNode* root; // each Trie data structure will have a root node
public:
    
    Trie() {
        root = new TrieNode();
        // we construct a new TrieNode whenever we start filling a Trie.
    }
    
    int cntUniqueSubstrings = 0;

    void insert(string word) {
        
        TrieNode* temp = root;
        
        for(int i=0; i<word.length(); i++) {
            int index = word[i] - 'a';
            
            if(temp->contains(index) == false) {
                temp->add(index);
            }
            
            temp = temp->getNextTrieNode(index);
        }
        
        
        if(temp->flag == false) {
            // this guarantees that current word appeared for first time in our trie.
            cntUniqueSubstrings++;
        }
        temp->markTrue();

    }
    
};

int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    int n = s.length();

    Trie trie;

    for(int i=0; i<n; i++) {
        string temp = "";
        for(int j=i; j<n; j++) {
            temp += s[j];
            trie.insert(temp);
        }
    }
    
    // here acc to question we need to count empty substring also 
    // hence add 1 to answer
    return trie.cntUniqueSubstrings + 1;

}

int main() {
    return 0;
}
