class Solution {
public:
    string findContestMatch(int n) {
        vector<string> res;
        for(int i=1; i<=n; i++) {
            res.push_back(to_string(i));
        }
        while(res.size()>1) {
            int i=0; int j=res.size()-1;
            vector<string> v;
            while(i<j) {
                string str = "(" + res[i] + "," + res[j] + ")";
                v.push_back(str);
                i++; j--;
            }
            res.clear();
            res = move(v);
        }
        return res[0];
    }
};