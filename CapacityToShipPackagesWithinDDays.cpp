class Solution {
public:
    int res = 0;
    int shipWithinDays(vector<int>& weights, int D) {
        if(weights.size()== D) return *max_element(weights.begin(),weights.end());
        int sumv=0;
        for(auto x:weights) {
            sumv+=x;
        }
        if(D==1) return sumv;
        return solution(weights,sumv,D,*max_element(weights.begin(),weights.end()),sumv);
    }
    int solution(vector<int>& weights, int sumv, int D, int low, int high) {
        if(low>=high) return res;
        int mid = low + (high-low)/2;
        int i = 0;
        int j = 0;
        int temp = 0;
        while(j<weights.size()) {
            if(temp+weights[j]>mid) {
                temp = weights[j];
                i++; j++;
            }
            else {
                temp += weights[j];
                j++;
            }
        }
        if(i < D){
            res = mid;
            solution(weights,sumv,D,low,mid);
        }
        else{
            solution(weights,sumv,D,mid+1,high);
        }
        return res;
    }
};