class CombinationIterator {
public:
    int k;
    vector<string> strs;
    int idx;
    void findallstrs(string remaining, string temp) {
        if(temp.length() == k) {
            strs.push_back(temp);
            return;
        }
        for(int i=0; i<remaining.length(); i++) {
            findallstrs(remaining.substr(i+1,remaining.length()),temp+remaining[i]);
        }
    }
    CombinationIterator(string characters, int combinationLength) {
        k = combinationLength;
        findallstrs(characters, "");
        idx = 0;
    }
    
    string next() {
        idx++;
        return strs[idx-1];
    }
    
    bool hasNext() {
        if(idx>=strs.size()) return false;
        return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */