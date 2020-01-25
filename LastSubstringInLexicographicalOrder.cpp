class Solution {
public:
    string lastSubstring(string s) {
        if(s.length()<2) return s;
        int n = s.length();
        int maxi = 0;
        int i = 1;
        while(i<n){
            if(s[i]>s[maxi]){
                maxi = i;
            }
            else if(s[i]==s[maxi]){
                int newi = i;
                int previ = i;
                int j = maxi;
                while(i<n && j<newi && s[i]==s[j]){
                    if(s[i]==s[maxi]){
                        previ = i;
                    }
                    i++; j++;
                }
                if(j==newi || i==n || s[j]>s[i]){
                    continue;
                }
                maxi = newi;
                if(newi!=previ){
                    i=previ;
                }
                continue;
            }
            i++;
        }
        return s.substr(maxi);
    }
};