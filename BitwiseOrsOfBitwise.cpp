class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        set<int> st;
        set<int> curr;
        int n = A.size();
        if(n<1) return 0;
        curr.insert(0);
        for(int i=0; i<n; i++){
            set<int> temp;
            for(int x:curr){
                temp.insert(x|A[i]);
            }
            temp.insert(A[i]);
            curr = temp;
            for(int x:curr) st.insert(x);
        }
        return st.size();
    }
};