class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int n = A.size();
        if(n<S) return 0;
        unordered_map<int,int> m;
        vector<int> p(n+1,0);
        for(int i=0; i<n; i++){
            p[i+1] = p[i]+A[i];
        }
        int res = 0;
        for(int i = 0; i<n+1; i++){
            res+=m[p[i]];
            
            m[p[i]+S]++;
        }
        return res;
    }
};