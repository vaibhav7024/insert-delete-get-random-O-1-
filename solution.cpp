class RandomizedSet {
public:
    unordered_map<int,int>idx;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(idx.find(val)!=idx.end()) return false;
        v.push_back(val);
        idx[val]=v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(idx.find(val)==idx.end()) return false;
        int index= idx[val];
        int last = v.size()-1;
        v[index]=v[last];
        idx[v[last]]=index;
        v.pop_back();
        idx.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
