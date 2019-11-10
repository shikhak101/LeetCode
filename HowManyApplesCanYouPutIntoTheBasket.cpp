class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int res = 0;
        int sum = 0;
        for(auto x:arr) {
            sum+=x;
            res++;
            if(sum>5000) return res-1;
        }
        return res;
    }
};