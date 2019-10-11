class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> v;
        int start = 0;
        for(int i=0; i<text.length(); i++) {
            if(text[i] == ' '){
                v.push_back(text.substr(start,i-start));
                start = i+1;
            }
        }
        v.push_back(text.substr(start,text.length()-start));
        vector<string> res;
        for(int i=0; i<v.size()-2; i++) {
            if(v[i] == first && v[i+1] == second) {
                res.push_back(v[i+2]);
            }
        }
        return res;
    }
};