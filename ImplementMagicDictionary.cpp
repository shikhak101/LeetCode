class MagicDictionary {
public:
    /** Initialize your data structure here. */
    map<int,vector<string>> m;
    MagicDictionary() {

    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto x:dict){
            int len = x.length();
            if(m.find(len) == m.end()) {
                vector<string> t;
                t.push_back(x);
                m.insert({len,t});
            }
            else{
                m[len].push_back(x);
            }
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int len = word.length();
        if(m.find(len) == m.end()) return false;
        for(int i=0; i<m[len].size(); i++) {
            string s = m[len][i];
            int diff = 0;
            for(int j = 0; j<word.length(); j++){
                if(s[j] != word[j]) diff++;
            }
            if(diff == 1) return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */