class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> res;
        vector<int> avg;
        map<int, vector<int>> m;
        for(int i=0; i<items.size(); i++) {
            if(m.find(items[i][0]) == m.end()) {
                vector<int> s;
                s.push_back(items[i][1]);
                m.insert({items[i][0],s});
            }
            else {
                m[items[i][0]].push_back(items[i][1]);
            }
        }
        for(auto x:m) {
            vector<int> t = x.second;
            sort(t.begin(),t.end());
            int sum = 0;
            int count = 0;
            for(int i=t.size()-1; i>=0; i--) {
                if(count>=5) break;
                count++;
                sum += t[i];
            }
            sum = sum/5;
            avg.push_back(x.first);
            avg.push_back(sum);
            res.push_back(avg);
            avg.clear();
        }
        return res;
    }
};