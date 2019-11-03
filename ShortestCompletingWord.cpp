class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        map<char,int> m;
        for(int i=0; i<licensePlate.length(); i++) {
            if(isalpha(licensePlate[i])) {
                char c = licensePlate[i];
                c = tolower(c);
                if(m.find(c) == m.end())
                    m.insert({c,1});
                else m[c]++;
            }
        }
        string res = "";
        int len = INT_MAX;
        for(int i = 0;i<words.size(); i++) {
            map<char,int> m1;
            for(int j = 0; j<words[i].length(); j++) {
                if(m1.find(words[i][j]) == m1.end()) 
                    m1.insert({words[i][j],1});
                else m1[words[i][j]]++;
            }
            int l = 0;
            for(auto k:m) {
                if(m1.find(k.first) == m1.end()) break;
                if(m1[k.first]<k.second) break;
                l++;
            }
            if(l == m.size()) {
                if(len > words[i].length()) {
                    res = words[i];
                    len = res.length();
                }
            }
        }
        return res;
    }
};