class Trie {
    public:
    map<char,Trie*> children;
    bool endWord= false;
};
class Solution {
public:
    vector<vector<char>> grid;
    int n; 
    int m; 
    set<string> res;
    vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
    void insertWord(string word, Trie* root) {
        Trie* curr = root;
        for(int i=0; i<word.length(); i++) {
            if(curr->children.find(word[i]) == curr->children.end()) {
                Trie* node = new Trie();
                curr->children.insert({word[i],node});
            }
            curr = curr->children[word[i]];
        }
        curr->endWord = true;
    }
    void backtrack(int a, int b, string curr, vector<vector<bool>>& vis, Trie* node){
        if(node->endWord == true) {
            res.insert(curr);
        }
        for(int i=0; i<4; i++) {
            int x = a+dirs[i].first;
            int y = b+dirs[i].second;
            if(x>=0 && y>=0 && x<n && y<m && vis[x][y] == false && node->children.find(grid[x][y])!=node->children.end()) {
                vis[x][y] = true;
                backtrack(x,y,curr+grid[x][y],vis,node->children[grid[x][y]]);
                vis[x][y] = false;
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ret;
        if(board.size() == 0) return ret;
        n = board.size();
        m = board[0].size();
        Trie* root = new Trie();
        for(int i=0; i<words.size(); i++) {
            insertWord(words[i],root);
        }
        grid = move(board);
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0; i<n; i++) {
            for(int j= 0; j<m; j++) {
                string curr = "";
                if(root->children.find(grid[i][j]) == root->children.end()) 
                    continue;
                vis[i][j] = true;
                backtrack(i,j,curr+grid[i][j],vis,root->children[grid[i][j]]);
                vis[i][j] = false;
            }
        }
        for(auto x:res) {
            ret.push_back(x);
        }
        return ret;
    }
};