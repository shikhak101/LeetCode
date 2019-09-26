class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        vector<pair<int,int>> v;
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            map<int, int>::iterator it = m.find(nums[i]);
            if(it == m.end()) {
                m.insert(make_pair(nums[i],1));
            }
            else {
                it->second++;
            }
        }
        for(map<int, int>::iterator it=m.begin(); it != m.end(); it++)
            v.push_back(make_pair(it->second,it->first));   
        make_heap(v.begin(),v.end());
        sort_heap(v.begin(), v.end()); 
        vector<pair<int,int>> v1;
        for(vector<pair<int, int>>::reverse_iterator it=v.rbegin(); it != v.rend(); it++) {
            v1.push_back(make_pair(it->first,it->second));
        }
        for(vector<pair<int, int>>::iterator it=v1.begin(); it != v1.end(); it++) {
            res.push_back(it->second);
            k--;
            if(k<=0) break;
        }
        return res;
    }
};