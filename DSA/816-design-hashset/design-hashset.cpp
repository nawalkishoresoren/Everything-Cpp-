class MyHashSet {
public:
    unordered_map<int,int>umap;
    MyHashSet() {
        
    }
    
    void add(int key) {
        umap[key]++;
        
    }
    
    void remove(int key) 
    {
        umap.erase(key);
        
    }
    
    bool contains(int key) 
    {
        if(umap.find(key)==umap.end())
            return false;
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */