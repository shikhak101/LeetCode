class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        if(S.length()==0) return res;
        res.push_back("");
        for(int i=0; i<S.length(); i++) {
            int n = res.size();
            char c = S[i];
            if(isalpha(c)) {
                for(int j=0; j<n; j++) {
                    res.push_back(res[j]);
                    res[j]+=tolower(c);
                    res[n+j]+=toupper(c);
                }
            }
            else {
                for(int j=0; j<n; j++) {
                    res[j]+=c;
                }
            }
        }
        return res;
    }
};