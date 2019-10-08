class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;
        string m[26] = {".-","-...","-.-.","-..",".","..-.","--.",
                         "....","..",".---","-.-",".-..","--","-.",
                         "---",".--.","--.-",".-.","...","-","..-",
                         "...-",".--","-..-","-.--","--.."};
        for(int i=0; i<words.size(); i++){
            string w = words[i];
            string code = "";
            for(int j=0; j<w.length(); j++){
                code += m[(int)w[j]-97];
            }
            s.insert(code);
        }
        return s.size();
    }
};