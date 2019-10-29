class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> res;
        map<int,int> m;
        for(auto x:arr1) {
            m.insert({x,1});
        }
        for(auto x:arr2) {
            if(m.find(x) != m.end()) {
                m[x]++;
            }
        }
        for(auto x:arr3) {
            if(m.find(x)!=m.end() && m[x] == 2){
                res.push_back(x);
            }
        }
        return res;
    }
};