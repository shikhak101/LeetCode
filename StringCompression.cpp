class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1;
        if(chars.size()<2) return chars.size();
        int j = 0;
        char ch = chars[0];
        for(int i=1; i<chars.size(); i++) {
            if(chars[i-1] == chars[i]) {
                count++;
            }
            int check = 0;
            if(i == chars.size()-1 && chars[i-1]!=chars[i]) {
                check = 1;
            }
            if(chars[i-1]!=chars[i] || i == chars.size()-1) {
                if(count>1) {
                    string c = to_string(count);
                    chars[j] = ch;
                    for(int k = 0; k<c.length(); k++) {
                        chars[++j] = c[k];
                    }
                    count = 1;
                }
                else if(count == 1) {
                    chars[j] = ch;
                }
                if(check == 1) {
                    chars[++j] = chars[i];
                }
                ch = chars[i];
                ++j;
            }
            
        }
        
        return j;
    }
};