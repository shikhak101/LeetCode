class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> locs;
        for(int i=0; i<S.length(); i++) {
            if(S[i] == C) locs.push_back(i);
        }
        vector<int> res;
        int start = locs[0], end = locs[0];
        int mid = (end - start) / 2;
        int k = 1;
        for(int i = 0; i<S.length(); i++) {
            if(i<=start+mid)
                res.push_back(abs(start-i));
            else res.push_back(abs(end-i));
            if(i == end) {
                start = end;
                if(k<locs.size()) end = locs[k++];
                mid = (end - start) / 2;
            } 
        }
        return res;
    }
};