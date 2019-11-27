struct Trie {
    map<char,Trie*>children;
    bool isEnd = false;
};
class Solution {
public:
    void insertTrie(string s, Trie* root) {
        Trie* curr = root;
        for(int i = 0; i<s.length(); i++) {
            char c = s[i];
            if(curr->children.find(c) == curr->children.end()) {
                curr->children.insert({c,new Trie()});
            }
            curr = curr->children[c];
        }
        curr->isEnd = true;
    }
    vector<string> searchTrie(string s, Trie* root) {
        Trie* curr = root;
        vector<string> v;
        for(int i = 0; i<s.length(); i++) {
            if(curr->children.find(s[i]) == curr->children.end()) {
                return v;
            }
            curr = curr->children[s[i]];
        }
        int count = 0;
        if(curr->isEnd == true){
            v.push_back(s);
            count++;
        }
        for(auto x:curr->children) {
            count = getList(x.second,s+x.first,count,v);
            if(count == 3) break;
        }
        return v;
    }
    int getList(Trie* curr, string s,int& count, vector<string>& v) {
        if(count == 3) return count;
        if(curr->isEnd == true) {
            v.push_back(s);
            count++;
        }
        for(auto x: curr->children) {
            getList(x.second,s+x.first,count,v);
            if(count == 3) break;
        }
        return count;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        Trie* root = new Trie();
        for(auto x:products) {
            insertTrie(x,root);
        }
        string w = "";
        for(int i = 0; i<searchWord.length(); i++) {
            w += searchWord[i];
            vector<string> v = searchTrie(w,root);
            res.push_back(v);
        }
        return res;
    }
};