class Solution {
public:
    vector<string> res;
    vector<string> expand(string S) {
        vector<vector<char>> v;
        int i=0;
        while(i<S.length()) {
            if(S[i] == '{') {
                vector<char> t;
                i++;
                while(S[i]!='}') {
                    if(S[i] != ',')
                        t.push_back(S[i]);
                    i++;
                }
                v.push_back(t);
            }
            else {
                vector<char> t;
                t.push_back(S[i]);
                v.push_back(t);
            }
            i++;
        }
        string e = "";
        res = solution(v,0,0,e);
        sort(res.begin(), res.end());
        return res;
    }
    vector<string> solution(vector<vector<char>> v, int i, int j, string each) {
        if(i>=v.size()) {
            res.push_back(each);
            return res;
        }
        if(j>= v[i].size()) {
            return res;
        }
        each += v[i][j];
        solution(v,i+1,0,each);
        solution(v, i, j+1,each.substr(0,each.length()-1));
        return res;
    }
};