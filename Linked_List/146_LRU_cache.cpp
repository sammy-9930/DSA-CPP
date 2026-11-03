/*
Using doubly linked list 
Time complexity : O(1) for each get() and put()
Space complexity : O(n) 
*/
class Node{
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};
class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node){
        Node* tmp = head->next;
        node->next = tmp;
        head->next = node;
        tmp->prev = node;
        node->prev = head;
    }

public:

    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
        }

        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if(cache.size() > cap){
            Node* lru = tail->prev;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

/*
Using built-in datastructure 
Time complexity : O(1) for each get() and put()
Space complexity : O(n) 
*/
class LRUCache {
private:
    int capacity;
    list<int> dll;
    unordered_map<int, pair<int, list<int>::iterator>> map;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(map.find(key) != map.end()){
            int value = map[key].first;
            dll.erase(map[key].second);
            dll.push_front(key);
            map[key].second = dll.begin();
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            dll.erase(map[key].second);
            map.erase(key);
        }

        dll.push_front(key);
        map[key] = {value, dll.begin()};


        if(map.size() > capacity){
            int key = dll.back();
            dll.pop_back();
            map.erase(key);
        }
    }
};
