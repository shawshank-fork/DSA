#include <stack>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;


class LRUCache {
    class Node {  //VERSION 1
    public:
        int key, val;
        Node *prev, *next;
        Node(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {}
    };

    int cap;
    unordered_map<int, Node*> m;
    Node *head, *tail;

    void addNode(Node *newNode) {
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node *delNode) {
        Node *prevNode = delNode->prev;
        Node *nextNode = delNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key_) {
        if (m.find(key_) != m.end()) {
            Node *resNode = m[key_];
            int val = resNode->val;
            deleteNode(resNode);
            addNode(resNode);
            m[key_] = head->next;
            return val;
        }
        return -1;
    }

    void put(int key_, int value) {
        if (m.find(key_) != m.end()) {
            Node *existingNode = m[key_];
            deleteNode(existingNode);
            m.erase(key_);
        }
        if (m.size() == cap) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node *newNode = new Node(key_, value);
        addNode(newNode);
        m[key_] = head->next;
    }
};


//VERSION 2
class LRUCache {
    int capacity;
    list<pair<int, int>> lru; // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> cache; // key -> iterator to list node

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;

        // Move the accessed node to front (most recently used)
        auto it = cache[key];
        int val = it->second;
        lru.erase(it);
        lru.push_front({key, val});
        cache[key] = lru.begin();
        return val;
    }
    
    void put(int key, int value) {
        // If key already exists, remove the old node
        if (cache.find(key) != cache.end()) {
            lru.erase(cache[key]);
        }

        // If cache is full, remove least recently used item (at back)
        if (lru.size() == capacity) {
            int keyToRemove = lru.back().first;
            lru.pop_back();
            cache.erase(keyToRemove);
        }

        // Insert new node at front (most recently used)
        lru.push_front({key, value});
        cache[key] = lru.begin();
    }
};



