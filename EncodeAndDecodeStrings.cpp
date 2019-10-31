class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        if(strs.size() == 0) return to_string((char)258);
        char d = (char)257;
        res = "";
        for(auto x:strs) {
            res+=x+d;
        }
        return res.substr(0,res.length()-1);
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        if(s == to_string((char)258)){
            return res;
        }
        char d = (char)257;
        string word = "";
        for(int i=0; i<s.length(); i++) {
            if(s[i] == d) {
                res.push_back(word);
                word = "";
            }
            else word+=s[i];
        }
        res.push_back(word);
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));