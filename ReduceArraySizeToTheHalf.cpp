class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return 0;
        map<int,int> m;
        for(int i=0; i<n; i++){
            m[arr[i]]++;
        }
        vector<int> v;
        for(auto x:m){
            v.push_back(x.second);
        }
        sort(v.begin(),v.end());
        int sum = 0;
        int res = 0;
        for(int i=v.size()-1; i>=0; i--){
            sum += v[i];
            res++;
            if(sum>=n/2){
                return res;
            }
        }
        return -1;
    }
};