class Solution {
public:
    int cnt = 0;
    string permute(string& res,string& s, int k, int l, int r) {
        if(l == r) {
            if(++cnt == k) res = s;
            return res;
        }
        for(int i=l; i<=r; i++) {
            string p = s;  
            if(i>l)
            {
                string t(1,s[i]);
                s.erase(i,1);
                s.insert(l,t);
            }
            permute (res, s, k,l+1,r);
            if(cnt == k) return res;
            s = p;
        }
        return res;
    }
    string getPermutation(int n, int k) {
        string s = "1";
        for(int i=2; i<=n; i++) {
            s += to_string(i);
        }
        string res = "";
        return permute(res,s,k, 0, s.length()-1);
        
    }
};