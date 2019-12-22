class Solution {
public:
    void findcont(vector<vector<int>>& cb,set<int>& c){
        queue<int> q;
        vector<bool> vis(cb.size(),false);
        for(auto x:c) {
            q.push(x);
            vis[x] = true;
        }
        while(!q.empty()) {
            int box = q.front();
            q.pop();
            for(int i=0; i<cb[box].size(); i++) {
                if(vis[cb[box][i]] == false) {
                    q.push(cb[box][i]);
                    c.insert(cb[box][i]);
                    vis[cb[box][i]] = true;
                }
            }
        }
    }
    void findkey(vector<vector<int>>& keys, set<int>& k, set<int>& c) {
        queue<int> q;
        vector<bool> vis(keys.size(),false);
        for(auto x:c){
            for(int i=0; i<keys[x].size(); i++) {
                q.push(keys[x][i]);
                vis[keys[x][i]] = true;
                k.insert(keys[x][i]);
            }
        }
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(int i=0; i<keys[curr].size(); i++) {
                if(vis[keys[curr][i]] == false) {
                    vis[keys[curr][i]] = true;
                    q.push(keys[curr][i]);
                    k.insert(keys[curr][i]);
                }
            }
        }
    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        set<int> k;
        set<int> c;
        int res = 0;
        for(int i=0; i<initialBoxes.size(); i++) {
            c.insert(initialBoxes[i]);
        }
        findcont(containedBoxes, c);
        findkey(keys,k,c);
        for(auto x:c) {
            if(status[x] == 1 || k.find(x)!=k.end()) {
                res = res+candies[x];
            }
        }
        return res;
    }
};