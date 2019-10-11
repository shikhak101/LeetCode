class Solution {
public:
    string removeDuplicates(string S) {
        if(S.length() <= 1) return S;
        int i=0; 
        int j = 1;
        while(j<S.length()) {
            if(i == j-1 && S[i] == S[j]) {
                S= S.substr(0,i) + S.substr(j+1,S.length()-j-1);
                if(i>0){
                    i=i-1;
                    j=j-1;
                }
            }
            else if(j<S.length()-1 && S[j] == S[j+1]) {
                i = j-1;
                S = S.substr(0,j) + S.substr(j+2,S.length()-j-2);
            }
            else j++;
        }
        return S;
    }
};