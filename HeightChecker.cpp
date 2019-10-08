class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> arr; 
        int res = 0;
        for(auto x : heights) arr.push_back(x);
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=heights[i]) res++;
        }
        return res;
    }
};