class MyHashMap {
public:
    map<int,int> myMap;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        myMap[key] = value;
    }
    
    int get(int key) {
        return myMap.contains(key) ? myMap[key] : -1;
    }
    
    void remove(int key) {
        myMap.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */