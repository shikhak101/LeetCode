class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char,int> m;
        for(int i=0; i<s.length(); i++) {
            if(m.find(s[i]) == m.end()){
                m.insert({s[i],1});
            }
            else m[s[i]]++;
        }
        int countofone = 0;
        for(auto x:m) {
            if(x.second % 2 == 1) countofone++;
            if(countofone > 1) return false;
        }
        return true;
    }
};