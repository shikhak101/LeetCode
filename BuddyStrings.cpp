class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.length() != B.length()) return false;
        set<char> s;
        int diff = 0;
        vector<int> loc;
        for(int i = 0; i<A.length(); i++)
        {
            s.insert(A[i]);
            if(A[i] != B[i]) {
                diff++;
                loc.push_back(i);
            }
           
        }
        if(A==B && A.length()>s.size()) return true;
        if(diff == 2 && A[loc[0]] == B[loc[1]] && A[loc[1]] == B[loc[0]]) return true;
        return false;
    }
};