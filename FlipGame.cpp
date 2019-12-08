class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        if(s.length() == 0) return res;
        for(int i=0; i<s.length()-1; i++) {
            if(s[i]=='+' && s[i+1]=='+') {
                string curr = s;
                curr[i] = '-';
                curr[i+1] = '-';
                res.push_back(curr);
            }
        }
        return res;
    }
};