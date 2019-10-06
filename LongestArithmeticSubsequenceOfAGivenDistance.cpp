class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int,int> m;
        int res = 1;
        for(int i = 0; i<arr.size(); i++) {
            if(m.find(arr[i]-difference) != m.end()) {
                m[arr[i]] = m[arr[i]-difference]+1;
            }
            else m[arr[i]] = 1;
            res = max(res,m[arr[i]]);
        }
        return res;
    }
};