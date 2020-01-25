class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        vector<int> v={INT_MAX};
        for(int i=0; i<arr.size(); i++) {
            while(v.back()<=arr[i]){
                int val = v.back();
                v.pop_back();
                res += val*min(arr[i],v.back());
            }
            v.push_back(arr[i]);
        }
        for(int i=2; i<v.size(); i++){
            res+= v[i]*v[i-1];
        }
        return res;
    }
};