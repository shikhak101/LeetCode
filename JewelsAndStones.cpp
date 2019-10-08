class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> js;
        for(int i=0; i<J.length(); i++) {
            js.insert(J[i]);
        }
        int count = 0;
        for(int i=0; i<S.length(); i++) {
            if(js.find(S[i])!=js.end()) ++count;
        }
        return count;
    }
};