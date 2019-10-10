class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string,int> m;
        for(auto x : cpdomains) {
            int num = 0;
            int idx = 0;
            for(int i=0; i<x.length(); i++) {
                if(x[i] == ' ') {
                    num = stoi(x.substr(0,i));
                    idx = i;
                }
            }
            for(int i=x.length()-1; i>=idx; i--) {
                if(x[i] == '.' || i == idx) {
                    string s = x.substr(i+1,x.length()-i-1);
                    if(m.find(s) == m.end()) {
                        m.insert(make_pair(s,num));
                    }
                    else {
                        m[s] += num;
                    }
                }
            }
        }
        vector<string> res;
        for(auto x: m) {
            string s = to_string(x.second) + " " + x.first;
            res.push_back(s);
        }
        return res;
    }
};