class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> res;
        map<string,pair<int,int>> m;
        int k1 = king[0]; int k2 = king[1];
        for(int i=0; i<queens.size(); i++) {
            int x = queens[i][0];
            int y = queens[i][1];
            if(x-k1 == 0) {
                string s = "";
                if(y-k2>0) s = "PR";
                else if(y-k2<0) s= "NR";
                if(m.find(s)==m.end()) {
                    m.insert({s,{(x*8+y),abs(y-k2)}});
                }
                else if(m[s].second>abs(y-k2)) {
                    m[s].first = (x*8)+y;
                    m[s].second = abs(y-k2);
                }
            }
            else if(y-k2==0) {
                string s = "";
                if(x-k1>0) s = "PC";
                else if(x-k1<0) s = "NC";
                if(m.find(s)==m.end()) {
                    m.insert({s,{(x*8+y),abs(x-k1)}});
                }
                else if(m[s].second>abs(x-k1)) {
                    m[s].first = (x*8)+y;
                    m[s].second = abs(x-k1);
                }
            }
            else if(abs(x-k1)==abs(y-k2)) {
                string s = "";
                if(x-k1<0 && y-k2>0) s = "D1";
                else if(x-k1>0 && y-k2>0) s = "D2";
                else if(x-k1>0 && y-k2<0) s = "D3";
                else if(x-k1<0 && y-k2<0) s = "D4";
                if(m.find(s)==m.end()) {
                    m.insert({s,{(x*8+y),abs(x-k1)}});
                }
                else if(m[s].second>abs(x-k1)) {
                    m[s].first = (x*8)+y;
                    m[s].second = abs(x-k1);
                }
            }
        }
        for(auto x:m) {
            int pos = x.second.first;
            int row = pos/8;
            int col = pos%8;
            vector<int> t;
            t.push_back(row);
            t.push_back(col);
            res.push_back(t);
        }
        return res;
    }
};