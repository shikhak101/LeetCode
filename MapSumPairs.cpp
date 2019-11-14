struct TrieNode{
    map<char,TrieNode*> children;
    int score;
};
class MapSum {
public:
    /** Initialize your data structure here. */
    map<string,int> m;
    TrieNode* root;
    MapSum() {
        m.clear();
        root = NULL;
    }
    
    void insert(string key, int val) {
        int delta = val;
        if(m.find(key) != m.end()) {
            delta = val - m[key];
            m[key] = val;
        } else {
            m.insert({key,val});
        }
        TrieNode* curr;
        if (root == NULL) { curr = new TrieNode(); root = curr;}
         else curr = root;
        curr->score += delta;
        for(int i=0; i<key.length(); i++) {
            char c = key[i];
            if(curr==NULL || curr->children.find(c) == curr->children.end()){
                if(curr == NULL) curr = new TrieNode();
                curr->children.insert({c,new TrieNode()});
            }
            curr = curr->children[c];
            if(curr!=NULL)
            curr->score += delta;
        }
    }
    
    int sum(string prefix) {
        TrieNode* curr = root;
        for(int i=0; i<prefix.length();i++) {
            char c = prefix[i];
            if(curr->children.find(c) == curr->children.end()) return 0;
            else curr = curr->children[c];
        }
        return curr->score;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */