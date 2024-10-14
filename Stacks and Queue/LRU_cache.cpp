
/**
https://www.youtube.com/watch?v=z9bJUPxzFOw&list=PLgUwDviBIf0pOd5zvVVSzgpo6BaCpHT9c&index=18
https://leetcode.com/problems/lru-cache/
**/

struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k, int v) {
        key = k;
        val = v;
        next = NULL;
        prev = NULL;
    }
};


class LRUCache {
public:


    // using Doubly linked list and map
    // initially DLL has 2 nodes 1 head and 1 tail

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    map<int, Node*> mp; // {key,node} pair
    int size_lim;

    LRUCache(int capacity) {
        size_lim = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {

        // if key is present in map
        if(mp.find(key) != mp.end()) {
            Node* temp = mp[key];

            // take node temp from current position to most recently used position i.e after head
            
            Node* before = temp->prev;
            Node* after = temp->next;

            before->next = after;
            after->prev = before;

            Node* mru = head->next;
            head->next = temp;
            temp->prev = head;
            temp->next = mru;
            mru->prev = temp;

            return temp->val;

        } 

        return -1;

    }
    
    void put(int key, int value) {
        

        if(mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            
            temp->val = value;
            // take the current node to mru position

            Node* before = temp->prev;
            Node* after = temp->next;

            before->next = after;
            after->prev = before;

            Node* mru = head->next;
            head->next = temp;
            temp->prev = head;
            temp->next = mru;
            mru->prev = temp;

            return;

        }

        // if key not present

        if(mp.size() == size_lim) {
            // delete the lru node that is node before tail
            Node* before = tail->prev->prev;
            Node* temp = tail->prev;

            before->next = tail;
            tail->prev = before;

            mp.erase(temp->key);
            delete temp;
        } 

        Node* temp = new Node(key, value);
        mp[key] = temp;

        // add this to mru position

        Node* mru = head->next;

        head->next = temp;
        temp->prev = head;
        temp->next = mru;
        mru->prev = temp;
        

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
