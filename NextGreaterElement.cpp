class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        stack<int> st;
        for(int i=0; i<nums2.size(); i++) {
            if(st.empty() || st.top()>nums2[i]) {
                st.push(nums2[i]);
            }
            else {
                while(!st.empty() && st.top()<nums2[i]) {
                    m.insert({st.top(),nums2[i]});
                    st.pop();
                }
                st.push(nums2[i]);
            }
        }
        while(!st.empty()){
            m.insert({st.top(),-1});
            st.pop();
        }
        vector<int> res;
        for(int i=0; i<nums1.size(); i++) {
            res.push_back(m[nums1[i]]);
        }
        return res;
    }
};