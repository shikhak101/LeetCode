class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        map<char,int> m1;
        for(int i=0; i<A.size(); i++) {
            map<char,int> m2;
            for(int j=0; j<A[i].length(); j++) {
                if(i == 0) {
                    if(m1.find(A[i][j]) == m1.end()) m1.insert(make_pair(A[i][j],1));
                    else m1[A[i][j]]++;
                }
                else {
                    if(m2.find(A[i][j]) == m2.end()) m2.insert(make_pair(A[i][j],1));
                    else m2[A[i][j]]++;
                }
            }
            if(i>0)
            {
                for(auto x:m1) {
                    if(m2.find(x.first)==m2.end()) m1[x.first] = 0;
                    else if(m2[x.first] < x.second) m1[x.first] = m2[x.first];
                }
            }
        }
        for(auto x:m1) {
            for(int i=0; i<x.second; i++){
                res.push_back(string(1,x.first));
            }
        }
        return res;
    }
};