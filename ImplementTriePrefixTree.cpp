struct TrieNode {
public:
    map<char,TrieNode*> children;
    bool isEnd=false;
};
class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        for(int i=0; i<word.length(); i++) {
            char c = word[i];
            if(curr->children.find(c) == curr->children.end()) {
                curr->children.insert({c,new TrieNode()});
            }
            curr = curr->children[c];
        }
        curr->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        for(int i=0; i<word.length(); i++){
            char c = word[i];
            if(curr->children.find(c) == curr->children.end()){
                return false;
            }
            curr = curr->children[c];
        }
        if(curr->isEnd == true) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i=0; i<prefix.length(); i++){
            char c = prefix[i];
            if(curr->children.find(c) == curr->children.end()){
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */