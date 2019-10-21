class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<pair<map<char,int>,map<char,int>>> st;
        for(auto x: A) {
            map<char,int> m;
            map<char,int> o;
            for(int i=0; i<x.size(); i++ ){
                if(i % 2 == 0) {
                    if(m.find(x[i]) == m.end()) m.insert({x[i],1});
                    else m[x[i]]++;
                }
                else {
                    if(o.find(x[i]) == o.end()) o.insert({x[i],1});
                    else o[x[i]]++;
                }
            }
            st.insert({m,o});
        }
        
        return st.size();
    }
};