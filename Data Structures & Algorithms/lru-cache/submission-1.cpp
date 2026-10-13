class Node{
public:
    Node(int key, int val)
    {
        this->value.first = key;
        this->value.second = val;
    }
    pair<int, int> value;
    Node* prev = nullptr;
    Node* next = nullptr;
};
class LRUCache {
public:
    LRUCache(int capacity) {
        maxSize = capacity;
        // Left = LRU
        left = new Node(0,0);
        // Right = MRU
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.contains(key) == 0) 
            return -1;
        Node* node = cache[key];
        remove(node);
        insert(node);
        return node->value.second;
    }
    
    void put(int key, int value) {
        if (cache.contains(key))
        {
            remove(cache[key]);
        }
        Node* newNode = new Node(key,value);
        cache[key] = newNode;
        insert(newNode);
        if (cache.size() > maxSize)
        {
            Node* lru = left->next;
            remove(lru); // Remove the LRU (left->next)
            cache.erase(lru->value.first);
            delete lru;
        }
    }
private:
    // Remove from Left
    void remove(Node* removeNode)
    {
        Node* next = removeNode->next;
        Node* prev = removeNode->prev;
        prev->next = next;
        next->prev = prev;
    }
    void insert(Node* insertNode)
    {
        Node* rightPrv = right->prev;
        rightPrv->next = insertNode;
        insertNode->prev = rightPrv;
        insertNode->next = right;
        right->prev = insertNode;
    }
    unordered_map<int,Node*> cache;
    int maxSize;
    Node* left;
    Node* right;
};


