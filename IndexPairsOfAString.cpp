class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        int pos = 0;
        vector<vector<int>> res;
        for(int i=0; i<text.length(); i++) {
            for(int j = i; j<text.length(); j++) {
                if(find(words.begin(),words.end(),text.substr(i,j-i+1)) != words.end()) {
                    vector<int> t;
                    t.push_back(i);
                    t.push_back(j);
                    res.push_back(t);
                }
            }
        }
        return res;
    }
};