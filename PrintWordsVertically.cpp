class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> v;
        int maxlen = 0;
        string w = "";
        for(int i=0; i<s.length(); i++) {
            if(s[i] == ' ') {
                v.push_back(w);
                int l = w.length();
                maxlen = max(maxlen,l);
                w = "";
            }
            else w+=s[i];
        }
        v.push_back(w);
        int l = w.length();
        maxlen = max(maxlen,l);
        vector<string> res(maxlen,"");
        for(int i=0; i<maxlen; i++) {
            for(int j=0; j<v.size(); j++) {
                int l = v[j].length();
                if(l-1<i){
                    res[i]+=" ";
                }
                else {
                    res[i]+=v[j][i];
                }
            }
        }
        for(int k = 0; k<res.size(); k++) {
            string x = res[k];
            if(x[x.length()-1] == ' ') {
                int i = x.length()-1;
                while(i>=0 && x[i] == ' ') {
                    i--;
                }
                res[k] = x.substr(0,i+1);
            }
        }
        return res;
    }
};