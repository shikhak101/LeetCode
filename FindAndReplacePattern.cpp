class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        
        for(int i=0; i<words.size(); i++) {
            map<char,int> w;
            map<char,int> p;
            int j;
            string s = words[i];
            for(j=0; j<s.length(); j++) {
                if(p.find(pattern[j]) == p.end() && w.find(s[j]) == w.end()){
                    p.insert(make_pair(pattern[j],j));
                    w.insert(make_pair(s[j],j));
                } 
                else if(p.find(pattern[j]) != p.end() && w.find(s[j]) != w.end() && p[pattern[j]] == w[s[j]]){
                    continue;           
                }
                else break;
            }
            if(j == s.length()) res.push_back(s);
        }
        return res;
    }
};