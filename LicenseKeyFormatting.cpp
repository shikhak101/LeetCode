class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int t = K;
        S.erase(remove(S.begin(),S.end(), '-'),S.end());
        int i = S.length()-1;
        while(i-K >= 0) {
            S.insert(S.begin()+i-(K-1),'-');
            i = i-K;
        }
        for(int i=0; i<S.length(); i++) {
            if(isalpha(S[i])) S[i] = toupper(S[i]);
        }
        return S;
    }
};