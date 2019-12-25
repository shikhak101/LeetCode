class Solution {
public:
    int countLetters(string S) {
        int res = 0;
        if(S.length()==0) return res;
        int n = S.length();
        for(int i=0; i<n; i++) {
            set<char> st;
            for(int j=i; j<n; j++) {
                st.insert(S[j]);
                if(st.size()>1) break;
                res++;
            }
        }
        return res;
    }
};