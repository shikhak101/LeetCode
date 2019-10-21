class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<vector<char>> v;
        vector<char> t = {'q','w','e','r','t','y','u','i','o','p'};
        v.push_back(t);
        t = {'a','s','d','f','g','h','j','k','l'};
        v.push_back(t);
        t = {'z','x','c','v','b','n','m'};
        v.push_back(t);
        vector<string> res;
        for(auto s : words) {
            int line = -1;
            string st=s;
            if(s.length()==0) continue;
            for(int j=0; j<s.length(); j++){
                s[j]=tolower(s[j]);
            }
            if(find(v[0].begin(),v[0].end(),s[0]) != v[0].end()) line = 0;
            else if(find(v[1].begin(),v[1].end(),s[0]) != v[1].end()) line = 1;
            else if(find(v[2].begin(),v[2].end(),s[0]) != v[2].end()) line = 2;
            if(line==-1) continue;
            for(int i = 0; i<s.length(); i++) {
                if(find(v[line].begin(),v[line].end(),s[i]) == v[line].end())
                    break;
                if(i == s.length()-1) res.push_back(st);
            }
        }
        return res;
    }
};