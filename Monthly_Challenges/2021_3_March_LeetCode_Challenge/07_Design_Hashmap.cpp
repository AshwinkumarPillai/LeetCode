class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<int>arr;
    
    MyHashMap() {
        for(int i= 0; i<=1000001;i++) arr.push_back(-1);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        arr[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return arr[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        put(key,-1);
    }
};

