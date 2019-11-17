struct Trie{
    map<char,Trie*> children;
    bool isEnd = false;
};
class Solution {
public:
    void insert(string s, Trie* curr) {
        for(int i=0; i<s.length(); i++) {
            if(curr->children.find(s[i]) == curr->children.end()) {
                curr->children.insert({s[i],new Trie()}); 
            }
            curr = curr->children[s[i]];
        }
        curr->isEnd = true;
    }
    string search(Trie* curr, string s) {
        string res = "";
        string t = "";
        for(int i=0; i<s.length(); i++) {
            if(curr->isEnd == true) {
                break;
            }
            else {
                if(curr->children.find(s[i]) == curr->children.end()) {
                    return t;
                }
                curr= curr->children[s[i]];
                res += s[i];
            }
        }
        if(curr->isEnd == true) return res;
        return t;
    }
    string replaceWords(vector<string>& dict, string sentence) {
        Trie* root = new Trie();
        for(auto x: dict) {
            insert(x,root);
        }
        string word = "";
        string res = "";
        for(int i=0; i<sentence.length(); i++) {
            if(sentence[i] == ' ' || i == sentence.length()-1) {
                if(i == sentence.length()-1) word += sentence[i];
                string s = search(root,word);
                if(s.length() == 0) {
                    res += word + ' ';
                }
                else {
                    res += s + ' ';
                }
                word = "";
            }
            else {
                word += sentence[i];
            }
        }
        return res.substr(0,res.length()-1);
    }
};