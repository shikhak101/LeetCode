class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int moves = 0;
        unordered_map<char,int> m;
        for(int i=0; i<keyboard.length(); i++) {
            m.insert({keyboard[i],i});
        }
        for(int i=0; i<word.length(); i++) {
            if(i==0)
                moves += m[word[i]];
            else {
                moves += abs(m[word[i]]-m[word[i-1]]);
            }
        }
        return moves;
    }
};