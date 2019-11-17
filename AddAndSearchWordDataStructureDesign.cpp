struct Trie{
    map<char,Trie*> children;
    bool isEnd=false;
};
class WordDictionary {
public:
    Trie* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Trie* curr = root;
        for(int i=0; i<word.length(); i++){
            if(curr->children.find(word[i]) == curr->children.end()) {
                curr->children.insert({word[i],new Trie()});
            }
            curr = curr->children[word[i]];
        }
        curr->isEnd=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        Trie* curr = root;
        Trie* lastword = curr;
        for(int i=0; i<word.length(); i++) {
            if(word[i] == '.'){
                for(auto x:curr->children){
                    string s = word;
                    s[i] = x.first;
                    if(search(s)) return true;
                }
            }
            if(curr->children.find(word[i]) == curr->children.end()) {
                return false;
            }
            curr = curr->children[word[i]];
            lastword = curr;
        }
        if(lastword->isEnd == true) return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */