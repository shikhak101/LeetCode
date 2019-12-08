class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size()==0 && popped.size()==0) return true;
        if(pushed.size()==0 || popped.size()==0) return false;
        stack<int> st;
        int i = 0; int j = 0;
        while(j<popped.size()) {
            while(i<pushed.size() && (st.empty() || st.top()!=popped[j])) {
                st.push(pushed[i++]);
            }
            if(st.top()!=popped[j]){
                return false;
            }
            while(j<popped.size() && !st.empty() && st.top()==popped[j]){
                st.pop();
                j++;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};