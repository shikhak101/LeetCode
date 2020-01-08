class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int s = 0; int e = n-1;
        while(s<=e) {
            int mid = s+(e-s)/2;
            if(citations[mid]== n-mid) {
                return n-mid;
            }
            else if(n-mid > citations[mid]) s = mid+1;
            else e = mid-1;
        }
        return n-s;
    }
};