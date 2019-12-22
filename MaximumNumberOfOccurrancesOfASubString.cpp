class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        int maxcount = 0;
        minSize = max(0,minSize);
        maxSize = min(n,maxSize);
        unordered_map<string,int> occ;
        while(minSize<=maxSize) {
            unordered_map<char,int> count;
            int start = 0;
            for(int i=0; i<n; i++) {
                count[s[i]]++;
                if(i-start+1>minSize) {
                    if(count[s[start]] == 1) count.erase(s[start]);
                    else count[s[start]]--;
                    start++;
                }
                if(i-start+1 == minSize && count.size()<=maxLetters) {
                    string word = s.substr(start,minSize);
                    occ[word]++;
                    maxcount = max(maxcount,occ[word]);
                }
            }
            minSize++;
        }
        return maxcount;
    }
};