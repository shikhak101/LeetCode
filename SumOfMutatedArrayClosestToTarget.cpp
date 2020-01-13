class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        if(arr.size() == 0) return 0;
        sort(arr.begin(),arr.end());
        int l = 0;
        int h = arr[arr.size()-1];
        int n = arr.size();
        int res = h; int diff = INT_MAX;
        while(l<=h) {
            int mid = (h+l)/2;
            int i=0;
            int sum = 0;
            while(i<n && arr[i]<mid) {
                sum += arr[i];
                i++;
            }
            sum += mid*(n-i);
            if(abs(target-sum) < diff) {
                diff = abs(target-sum);
                res = mid;
            }
            else if(abs(target-sum) == diff) {
                res = min(res,mid);
            }
            if(sum>target) h = mid-1;
            else if(sum == target) h--;
            else l = mid+1;
        }
        return res;
    }
};