class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0;
        int B = 0;
        map<char,int> s;
        for(auto x:secret) {
            if(s.find(x) == s.end()) s.insert(make_pair(x,1));
            else s[x]++;
        }
        map<char,int> t;
        for(int i = 0; i<secret.length(); i++) {
            if(secret[i] == guess[i]){
                A++;
                if(t.find(guess[i]) == t.end()) {
                    t.insert(make_pair(guess[i],1));
                }
                else {
                    t[guess[i]]++;
                }
            }
        }
        for(int i = 0; i<secret.length(); i++) {
            if(secret[i] != guess[i]){
                if(s.find(guess[i]) != s.end()) {
                    if(t.find(guess[i]) == t.end()){
                        t.insert(make_pair(guess[i],1));
                        B++;
                    }
                    else if(s[guess[i]] > t[guess[i]]){
                        B++;
                        t[guess[i]]++;
                    }
                }
            }
        }
        string res = to_string(A) + 'A' + to_string(B) +'B';
        return res;
    }
};