class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> result;
        stack<int> st;
        for(int i=0; i<A.size(); i++) {
            if(A[i]<0) {
                st.push(A[i]);
                continue;
            }
            while(!st.empty() && abs(st.top())<A[i]) {
                result.push_back(st.top()*st.top());
                st.pop();
            }
            result.push_back(A[i]*A[i]);
        }
        while(!st.empty()) {
            result.push_back(st.top()*st.top());
            st.pop();
        }
        return result;
    }
};