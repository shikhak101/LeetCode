class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int res = 0;
        int n=dominoes.size();
        if(n==0) return res;
        unordered_map<string,pair<int,int>> m;
        for(int i=0; i<n; i++) {
            string s = "";
            if(dominoes[i][0]<dominoes[i][1]){
                s = to_string(dominoes[i][0]) + ":" + to_string(dominoes[i][1]);
            }
            else{
                s = to_string(dominoes[i][1]) + ":" + to_string(dominoes[i][0]);
            }
            if(m.find(s)==m.end()) {
                m.insert({s,{1,0}});
            }
            else {
                m[s].second += m[s].first;
                m[s].first++;
            }
        }
        for(auto x:m) {
            res+=x.second.second;
        }
        return res;
    }
};