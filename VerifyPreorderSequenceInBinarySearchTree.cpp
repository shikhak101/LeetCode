class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if(preorder.size()<=2) return true;
        for(int i=0; i<preorder.size()-2; i++) {
            int curr = preorder[i];
            int j = i+1;
            while(j<preorder.size() && preorder[j]<curr) j++;
            while(j<preorder.size() && preorder[j]>curr) j++;
            if(j!=preorder.size()) return false;
        }
        return true;
    }
};