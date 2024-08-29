//https://leetcode.com/problems/replace-words/description/

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

class Trie {
    TrieNode* root;
public:

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
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

    string smallestRoot(string word) {

        string ans;
        TrieNode* temp = root;

        for(int i=0; i<word.length(); i++) {

            // at any moment if we find flag == true then we have a valid root. Return string ans as we want smallest valid root
            if(temp->flag == true) {
                return ans;
            }

            ans += word[i];
            int index = word[i] - 'a';

            if(temp->contains(index) == false) {
                // no valid root exists hence return the string Word itself as per question
                return word;
            }

            temp = temp->getNextTrieNode(index);

        }

        if(temp->flag == true) {
            return ans;
        }
        return word;

    }


};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for(string s:dictionary) {
            trie.insert(s);
        }

        string res = "";
        string curr = "";
        for(int i=0; i<sentence.length(); i++) {
            if(sentence[i] == ' ') {
                string s = trie.smallestRoot(curr);
                curr = "";
                res += s;
                res += " ";
            } else {
                curr += sentence[i];
            }
        }

        string s = trie.smallestRoot(curr);
        // as sentence do not have trailing spaces
        res += s;

        return res;

    }
};
