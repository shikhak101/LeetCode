class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        unordered_map<string,vector<int>> m;
        for(int i=0; i<phrases.size(); i++) {
            string phrase = phrases[i];
            string firstword = "";
            int j=0;
            while(j<phrase.size() && phrase[j]!=' ') {
                firstword += phrase[j];
                j++;
            }
            if(m.find(firstword) == m.end()){
                vector<int> t;
                t.push_back(i);
                m.insert({firstword,t});
            }
            else
                m[firstword].push_back(i);
        }
        set<string> res;
        for(int i=0; i<phrases.size(); i++) {
            string phrase = phrases[i];
            string lastword = "";
            int j=phrase.size()-1;
            while(j>=0 && phrase[j]!=' ') {
                lastword = phrase[j] + lastword;
                j--;
            }
            if(m.find(lastword)  == m.end()) continue;
            for(int k=0; k<m[lastword].size(); k++) {
                if(i==m[lastword][k]) continue;
                string newph = phrase;
                string sufph = phrases[m[lastword][k]];
                string suffix = "";
                if(sufph.size()>lastword.size()) {
                    suffix = " " + sufph.substr(lastword.size()+1,sufph.size());
                }
                newph += suffix;
                res.insert(newph);
            }
        }
        vector<string> ret;
        for(auto x:res) {
            ret.push_back(x);
        }
        return ret;
    }
};