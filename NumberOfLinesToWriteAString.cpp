class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int count = 0;
        for(auto x:S) {
            int i = (int)x;
            i = i-97;
            int num = widths[i];
            if(count/100 < (count + num)/100 && (count+num)%100!=0){
                int d = (count+num)/100;
                count = 100*(d) + num;
            }
            else count += num;
        }
        vector<int> res;
        if(count % 100 == 0) res.push_back(count/100);
        else res.push_back(count/100 +1);
        res.push_back(count%100);
        return res;
    }
};