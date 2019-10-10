class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int> m;
        for(int i=0; i<chars.length(); i++) {
            if(m.find(chars[i])!=m.end()) {
                m[chars[i]]++;
            }
            else m.insert(make_pair(chars[i],1));
        }
        int res = 0;
        for(auto x:words) {
            map<char,int> m1;
            int i = 0;
            for( i=0; i<x.length(); i++) {
                if(m.find(x[i]) == m.end()) break;
                if(m1.find(x[i])!=m1.end()) {
                    m1[x[i]]++;
                }
                else m1.insert(make_pair(x[i],1));
            }
            if(i<x.length()) continue;
            int dontadd = 0;
            for(auto y:m1) {
                if(m[y.first] < m1[y.first]){
                    dontadd = 1;
                    break;
                }
            }
            if(dontadd == 0) res += x.length();
        }
        return res;
    }
};