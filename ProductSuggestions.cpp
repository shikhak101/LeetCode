#include<iostream>
#include<vector>
#include<map>
using namespace std;
class TrieNode {
    public:
    map<char,TrieNode*> children;
    bool islastword;
};

TrieNode* lookup(char c,TrieNode* node){
    if(node->children.find(c) == node->children.end()) return NULL;
    return node->children[c];
}
void insert(TrieNode* root, string word){
    TrieNode* node = root;
    int i=0;
    for(i=0; i<word.size(); i++){
        if(word[i]>=65 && word[i]<=90) word[i]+=32;
        TrieNode* found  = lookup(word[i],node);
        
        if(found==NULL){
            TrieNode* t = new TrieNode();
            TrieNode* t1 = NULL;
            t->children.insert(make_pair(word[i],t1));
            t->islastword = false;
            node->children[word[i]] = t;
        }
        node = node->children[word[i]];
    }
    node->islastword = true;
}
void get_suggestions(TrieNode* node, vector<string>& ans, string word) {
    if(node == NULL) return;
    if(ans.size() >=3) return;
    if(node->islastword == true) {
        ans.push_back(word);
    }
    for(auto x: node->children){
        // cout<<x.first<<endl;
        word += (x.first);
        get_suggestions(x.second,ans,word);
        word.pop_back();
    }
}
vector<string> suggestions(TrieNode* root, string query) {
    TrieNode* node = root;
    int i=0;
    for(i=0; i<query.length(); i++){
        char c = query[i];
        if(c>=65 && c<=90) c+=32;
        TrieNode* t = NULL;
        if(node->children.find(c) != node->children.end()){
            t = node->children[c];
            node = t;
        }
        else break;
    }
    vector<string> res;
    if(i == query.length()){
        get_suggestions(node,res,query);
    }
    return res;
}

int main() {
    int numProducts=5;
    string repository[5]={"moBile", "mOUse", "moneypot", "monitor", "mousepad"};
    string customerQuery="mouse";

    struct TrieNode* root = new TrieNode();
    for(int i=0;i<numProducts;i++) {
        insert(root, repository[i]);
    }
    for(int i=1;i<customerQuery.size();i++) {
        vector<string>ans = suggestions(root, customerQuery.substr(0, i+1));
        for(auto it=ans.begin();it!=ans.end();it++) {
            cout<<*it<<" ";
        }
        cout<<"\n";
    }
}
