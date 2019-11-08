class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        set<char> st;
        int res = 0;
        int prev = 0;
        for(int i=0; i<S.length(); i++) {
            int j = i;
            for(j = i; j<i+K && j<S.length(); j++) {
                int prev = st.size();
                st.insert(S[j]);
                if(prev == st.size()) break;
            }
            if(st.size() == K) {
                res++;
            }
            st.clear();
        }
        return res;
    }
};