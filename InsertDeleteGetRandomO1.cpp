class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> st;
    unordered_map<int,int> m;
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val) != m.end()) return false;
        st.push_back(val);
        m[val] = st.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val) == m.end()) return false;
        int pos = m[val];
        int last = st[st.size()-1];
        st[pos] = last;
        st[st.size()-1] = val;
        st.pop_back();
        m[last] = pos;
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(st.size() == 0) return -1;
        int val = rand() % st.size();
        return st[val];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */