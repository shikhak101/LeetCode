class Solution {
public:
    int shortestWay(string s, string tg) {
        if(tg.length()==0) return 0;
        if(s.length() == 0) return -1;
        map<char, vector<int>> m;
        for(int i=0; i<s.length(); i++) {
            char c = s[i];
            if(m.find(c) == m.end()) {
                vector<int> t;
                t.push_back(i);
                m.insert({c,t});
            }
            else {
                m[c].push_back(i);
            }
        }
        int count = 1; int curr = -1;
        for(int i=0; i<tg.length(); i++)
        {
            char c = tg[i];
            if(m.find(c) == m.end()) return -1;
            vector<int> t = m[c];
            // cout<<c<<"--"<<curr<<endl;
            if(upper_bound(t.begin(), t.end(), curr) == t.end()){
                count++;
                curr = -1;
                curr = t[upper_bound(t.begin(), t.end(), curr)-t.begin()];
                cout<<tg.substr(0,i+1)<<endl;
            }
            else {
                curr =t[upper_bound(t.begin(), t.end(), curr) - t.begin()];
            }
        }
        return count;
    }
};