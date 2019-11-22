class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> n1;
        map<int,int> n2;
        for(int i=0; i<nums1.size(); i++) {
            if(n1.find(nums1[i]) == n1.end()) {
                n1.insert({nums1[i],1});
            }
            else n1[nums1[i]]++;
        }
        for(int i=0; i<nums2.size(); i++) {
            if(n2.find(nums2[i]) == n2.end()) {
                n2.insert({nums2[i],1});
            }
            else n2[nums2[i]]++;
        }
        vector<int> res;
        for(int i=0; i<nums1.size(); i++) {
            if(n2.find(nums1[i]) != n2.end() && find(res.begin(),res.end(),nums1[i])==res.end()) {
                int minv = min(n2[nums1[i]],n1[nums1[i]]);
                while(minv>0) {
                    minv--;
                    res.push_back(nums1[i]);
                }
            }
        }
        return res;
    }
};