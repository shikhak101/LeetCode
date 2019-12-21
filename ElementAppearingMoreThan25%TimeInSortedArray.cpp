class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = .25 * arr.size();
        int res = arr[0];
        int prev = res;
        int count = 1;
        for(int i=1; i<arr.size(); i++) {
            if(prev == arr[i]){
                count++;
            }
            else {
                if(count>n){
                    res = prev;
                }
                count = 1;
                prev = arr[i];
            }
        }
        if(count>n){
            res = prev;
        }
        return res;
    }
};