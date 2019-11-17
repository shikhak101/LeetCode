struct TrieNode{
    map<char,TrieNode*> children;
    bool isEnd=false;
};
class Solution {
public:
    void insert(string s, TrieNode* curr){
        for(int i=0; i<s.length(); i++){
            if(curr->children.find(s[i]) == curr->children.end()) {
                curr->children.insert({s[i],new TrieNode()});
            }
            curr = curr->children[s[i]];
        }
    }
    bool search(string s, string p, TrieNode* curr) {
        int j = 0;
        for(int i=0; i<s.length(); i++){
            if(j<p.length() && s[i]== p[j]){
                j++;
            }
            else {
                if(s[i]<=90) return false;
            }
            curr = curr->children[s[i]];
        }
        if(j==p.length()) return true;
        return false;
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        TrieNode* root;
        root = new TrieNode();
        for(auto x:queries){
            insert(x,root);
        }
        vector<bool> res;
        
        for(auto x:queries) {
            TrieNode* curr = root;
            res.push_back(search(x,pattern,root));
        }
        return res;
    }
};