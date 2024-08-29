//https://leetcode.com/problems/design-add-and-search-words-data-structure/

struct TrieNode {
    bool flag = false;
    TrieNode* arr[26] = {NULL};

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

class WordDictionary {
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* temp = root;

        for(int i=0; i<word.length(); i++) {
            int index = word[i] - 'a';

            if(temp->contains(index) == false) {
                temp->add(index);
            }

            temp = temp->getNextTrieNode(index);
        }

        temp->flag = true;
    }
    
    bool dfs(int i, string& word, TrieNode* temp) {

        if(i == word.length()) {
            return temp->flag; // V.V imp yaha true mat return kardena Pehle check karna
        }

        if(word[i] != '.') {
            int index = word[i] - 'a';
            if(temp->contains(index) == false) {
                return false;
            }
            TrieNode* temp2 = temp->getNextTrieNode(index);
            return dfs(i+1, word, temp2);
        }

        for(int index = 0; index < 26; index++) {

            if(temp->contains(index) == true) {
                TrieNode* temp2 = temp->getNextTrieNode(index);

                if(dfs(i+1, word, temp2) == true) {
                    return true;
                }
            }
        }
        return false;

    }


    bool search(string word) {
        
        return dfs(0,word,root);

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
