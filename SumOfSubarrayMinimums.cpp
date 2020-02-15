class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        if(n==0) return 0;
        int res = 0;
        stack<pair<int,int>> st;
        int val = 0;
        for(int i=0; i<n; i++){
            int count = 1;
            while(!st.empty() && st.top().first>=A[i]){
                int curr = st.top().second;
                int v = st.top().first;
                st.pop();
                count += curr;
                val -= v*curr;
            }
            st.push({A[i],count});
            val += A[i]*count;
            res+=val;
            res%=1000000007;
        }
        return res;
    }
};