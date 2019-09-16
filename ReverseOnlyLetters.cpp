class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0; 
        int j = S.length() - 1;
        while(i < S.length() && j >= 0 && i<j) {
            if(!isalpha(S[i])) i++;
            else if(!isalpha(S[j])) j--;
            else {
                char c = S[i];
                S[i] = S[j];
                S[j] = c;
                i++;
                j--;
            }
        }
        return S;
    }
};