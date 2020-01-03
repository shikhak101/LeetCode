class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        int num = label;
        res.push_back(num);
        int l=0;
        int n = 0;
        while(num>=pow(2,n)) {
            n++;
            l++;
        }
        l--;
        while(l>0) {
            int pos;
            if(l%2 == 0)
                pos = (num-pow(2,l)+1+1)/2;
            else
                pos = (pow(2,l)-(num-pow(2,l))+1)/2;
            if(l%2 == 0)
                num = pow(2,l)-pos;
            else num = pow(2,(l-1))+pos-1;
            res.push_back(num);
            l--;
        }
        int i=0; int j=res.size()-1;
        while(i<j) {
            swap(res[i],res[j]);
            i++; j--;
        }
        return res;
    }
};