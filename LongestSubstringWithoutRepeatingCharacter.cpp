class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0; 
        int end = 0;
        map <char, int> m;
        int len=0;
        int maxlen = 0;
        for(int i=0; i<s.length(); i++)
        {
            map<char,int>::iterator it = m.find(s[i]);
            if(it == m.end() || it->second < start) {
                len = end - start + 1;
                if(maxlen < len) {
                    maxlen = len;
                    cout<<s.substr(start,len)<<"\n";
                }
                if(it != m.end()) it->second = i;
                else m.insert(pair(s[i], i));
            }
            else {
                if(it->second >= start) start = it->second + 1;
                else start = start+1;
                it->second = i;
            }
            end++;
        }
        return maxlen;
    }
};