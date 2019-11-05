class Solution {
public:
    string removeVowels(string S) {
        for(int i=0; i<S.length(); i++) {
            if(S[i]=='a' || S[i]=='e' || S[i]=='i' || S[i]=='o' || S[i]=='u') {
                S = S.substr(0,i) + S.substr(i+1,S.length());
                i--;
            }
        }
        return S;
    }
};