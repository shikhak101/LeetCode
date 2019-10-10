class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> m;
        for(int i=0; i<arr1.size(); i++) {
            if(m.find(arr1[i]) == m.end()) m.insert(make_pair(arr1[i],1));
            else m[arr1[i]]++;
        }
        
        int k = 0;
        for(auto x: arr2) {
            for(int i=0; i<m[x]; i++) {
                arr1[k++] = x;
            }
            m.erase(x);
        }
        for(auto x: m) {
            for(int i=0; i<x.second; i++) {
                arr1[k++] = x.first;
            }
        }
        return arr1;
    }
};