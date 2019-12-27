// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        set<int> st;
        for(int i=0; i<n; i++) {
            st.insert(i);
        }
        for(int i=0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(i == j) continue;
                if(knows(i,j) == true) {
                    st.erase(i);
                }
                if(knows(i,j) == false) {
                    st.erase(j);
                }
                if(st.size()==0) return -1;
            }
        }
        for(auto x:st) return x;
        return -1;
    }
};