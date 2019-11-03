class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> m;
        for(int i=0; i<order.length(); i++) {
            m.insert({order[i],i+1});
        }
        for(int i=0; i<words.size()-1; i++) {
            int j = 0; int k = 0;
            while(j<words[i].length() && k<words[i+1].length()) {
                if(words[i][j] == words[i+1][k]) {
                    j++; k++;
                }
                else if(m[words[i][j]] < m[words[i+1][k]]) break;
                else {
                    return false;
                }
            }
            if(k == words[i+1].length() && j<words[i].length()) return false;
        }
        return true;
    }
};