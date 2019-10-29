class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> m;
        for(int i=0; i<text.length(); i++) {
            if(m.find(text[i]) == m.end()) {
                m.insert({text[i],1});
            }
            else {
                m[text[i]]++;
            }
        }
        int res = 0;
        while(true) {
            if(m.find('b') == m.end() || m['b'] < 1) break;
            else m['b']--;
            if(m.find('a') == m.end() || m['a'] < 1) break;
            else m['a']--;
            if(m.find('l') == m.end() || m['l'] < 2) break;
            else m['l'] -= 2;
            if(m.find('o') == m.end() || m['o'] < 2) break;
            else m['o'] -= 2;
            if(m.find('n') == m.end() || m['n'] < 1) break;
            else m['n']--;
            ++res;
        }
        return res;
    }
};