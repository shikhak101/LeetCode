struct TrieNode {
    struct TrieNode *children[26];
    bool isendofword;
};
class Solution {
public:
    void insert(TrieNode* root, string word) {
        TrieNode* curr = root;
        for(int i=0; i<word.length(); i++) {
            int idx = word[i]-'a';
            if(!curr->children[idx]){
                TrieNode *temp = NULL;
                temp = new TrieNode();
                temp->isendofword = false;
                for(int i=0; i<26; i++) temp->children[i] = NULL;
                curr->children[idx] = temp;
            }
            curr = curr->children[idx];
        }
        curr->isendofword = true;
    }
    bool search(TrieNode* root, string word) {
        TrieNode* curr = root;
        for(int i=0; i<word.length(); i++) {
            int idx = word[i]-'a';
            if(!curr->children[idx]) return false;
            curr = curr->children[idx];
            if(curr->isendofword == false) return false;
        }
        if(curr!=NULL && curr->isendofword == true) return true;
        return false;
    }
    string longestWord(vector<string>& words) {
        TrieNode* root = NULL;
        string res = "";
        root = new TrieNode();
        root->isendofword = false;
        for(int i=0; i<26; i++) root->children[i] = NULL;
        for(int i=0; i<words.size(); i++) {
            insert(root,words[i]);
        }
        for(int i=0; i<words.size(); i++) {
            bool check = search(root,words[i]);
            if(check == true) {
                if(res.length()<words[i].length()) res = words[i];
                else if(res.length() == words[i].length()) {
                    if(res>words[i]) res = words[i];
                }
            }
        }
        return res;
    }
};