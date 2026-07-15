class MyHashSet {
public:
    vector<bool>hash_set;
    MyHashSet() {
        hash_set.resize(1000001,false);
    }
    
    void add(int key) {
        hash_set[key] = true;
        
    }
    
    void remove(int key) 
    {
        hash_set[key] = false;
        
    }
    
    bool contains(int key) 
    {
        return hash_set[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */