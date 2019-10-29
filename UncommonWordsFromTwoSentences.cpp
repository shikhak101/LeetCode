class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        map<string,int> m;
        map<string,int> m1;
        vector<string> uncommon;
        string word = "";
        for(int i=0; i<A.length(); i++) {
            if(A[i] == ' ') {
                if(m.find(word) == m.end()) {
                    m.insert({word,1});
                }
                else m[word]++;
                word = "";
            }
            else word += A[i];
            if(i == A.length()-1) {
                if(m.find(word) == m.end()) {
                    m.insert({word,1});
                }
                else m[word]++;
                word = "";
            }
        }
        word = "";
        for(int i=0; i<B.length(); i++) {
            if(B[i] == ' ') {
                if(m1.find(word) == m1.end()) {
                    m1.insert({word,1});
                }
                else m1[word]++;
                word = "";
            }
            else word+=B[i];
            if(i == B.length()-1) {
                if(m1.find(word) == m1.end()) {
                    m1.insert({word,1});
                }
                else m1[word]++;
                word = "";
            }
        }
        for(auto x:m) {
            if(m1.find(x.first) == m1.end() && x.second == 1) 
                uncommon.push_back(x.first);
        }
        for(auto x:m1) {
            if(m.find(x.first) == m.end() && x.second == 1) uncommon.push_back(x.first);
        }
        return uncommon;
    }
};