class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> n1;
        vector<int> res;
        for(int i=0; i<nums1.size(); i++) {
            n1.insert(nums1[i]);
        }
        for(int i=0; i<nums2.size(); i++) {
            if(n1.find(nums2[i]) != n1.end() && find(res.begin(),res.end(),nums2[i]) == res.end()) 
                res.push_back(nums2[i]);
        }
        return res;
    }
};