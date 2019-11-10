class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> res;
        int i = 0;
        int j = S.length();
        int k=0;
        for(k=0; k<S.length(); k++) {
            if(S[k] == 'I'){
                res.push_back(i); i++;
            }
            else {
                res.push_back(j); j--;
            }
        }
        if(S[k-1] == 'I'){
            res.push_back(i); i++;
        }
        else if(S[k-1] == 'D') {
            res.push_back(j); j--;
        }
        return res;
    }
};