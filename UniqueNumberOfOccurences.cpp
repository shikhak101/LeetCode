class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> m;
        set<int> s;
        for(int i=0; i<arr.size(); i++){
            if(m.find(arr[i])==m.end()){
                m.insert(make_pair(arr[i],1));
            }
            else {
                m[arr[i]]++;
            }
        }
        for(auto x:m) {
            s.insert(x.second);
        }
        if(s.size()==m.size()) return true;
        return false;
    }
};