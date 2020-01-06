bool comp(pair<string,int> const & t1, pair<string,int> const & t2){
    if(t1.second==t2.second){
        return t1.first<t2.first;
    }
    return t1.second<t2.second;
}
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = watchedVideos.size();
        unordered_map<string,int> trgt;
        queue<pair<int,int>> q;
        vector<bool> vis(n,false);
        q.push({id,0});
        vis[id] = true;
        while(!q.empty()) {
            int slf = q.front().first;
            int l = q.front().second;
            if(l==level) break;
            q.pop();
            for(int i=0; i<friends[slf].size(); i++) {
                if(friends[slf][i]!=id && vis[friends[slf][i]] == false) {
                    q.push({friends[slf][i],l+1});
                    vis[friends[slf][i]]=true;
                    if(l+1==level) {
                        for(int j=0; j<watchedVideos[friends[slf][i]].size(); j++) {
                            trgt[watchedVideos[friends[slf][i]][j]]++;
                        }
                    }
                }
            }
        }
        vector<pair<string,int>> v(trgt.begin(),trgt.end());
        sort(v.begin(),v.end(),comp);
        vector<string> res;
        for(auto x:v) {
            res.push_back(x.first);
        }
        return res;
    }
};