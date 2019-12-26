class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(),d.end());
        int maxlen = 0;
        string res = "";
        for(int i=0; i<d.size(); i++) {
            string curr = d[i];
            int j = 0;
            int k = 0;
            while(j<s.size() && k<curr.size()) {
                if(curr[k] == s[j]) {
                    k++;
                }
                j++;
            }
            if(k==curr.size()) {
                if(maxlen<curr.size()) {
                    maxlen = curr.size();
                    res = curr;
                }
            }
        }
        return res;
    }
};