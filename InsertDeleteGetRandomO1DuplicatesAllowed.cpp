class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    vector<int> v;
    unordered_map<int,vector<int>> m;
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool b = true;
        if(m.find(val) != m.end()) b = false;
        v.push_back(val);
        m[val].push_back(v.size()-1);
        return b;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(m.find(val) == m.end()) return false;
        if(v[v.size()-1] == val) {
            v.pop_back();
            if(m[val].size()==1) m.erase(val);
            else m[val].pop_back();
        }
        else {
            int last = v[v.size()-1];
            int pos = m[val][m[val].size()-1];
            v[pos] = last;
            m[last].pop_back();
            m[last].insert(m[last].begin(),pos);
            v.pop_back();
            if(m[val].size()==1) m.erase(val);
            else m[val].pop_back();
        }
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        if(v.size()==0) return -1;
        int val = rand()%v.size();
        return v[val];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */