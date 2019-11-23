class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,int> m1;
        map<string,int> m2;
        int i=0;
        for(auto x:list1) {
            m1.insert({x,i});
            i++;
        }
        i = 0;
        for(auto x:list2) {
            m2.insert({x,i});
            i++;
        }
        int minidx = INT_MAX;
        vector<string> res;
        for(auto x:m1) {
            if(m2.find(x.first) != m2.end()) {
                if(minidx > (m2[x.first] + x.second)) {
                    minidx = m2[x.first] + x.second;
                    res.clear();
                    res.push_back(x.first);
                }
                else if(minidx == (m2[x.first] + x.second)) {
                    res.push_back(x.first);
                }
            }
        }
        return res;
    }
};