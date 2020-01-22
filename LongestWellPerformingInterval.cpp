class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int res = 0;
        if(hours.size()==0) return res;
        int curr = 0;
        unordered_map<int,int> m;
        for(int i=0;i<hours.size(); i++){
            if(hours[i]<=8) curr--;
            else curr++;
            if(curr>0) res = i+1;
            else{
                if(m.find(curr) == m.end()) m.insert({curr,i});
                if(m.find(curr-1)!=m.end()) res = max(res,i-m[curr-1]);
            }
        }
        return res;
    }
};