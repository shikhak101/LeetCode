class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int mindist = 999999;
        int other = 0;
        int missing = 0;
        for(int i=0; i<arr.size()-1; i++) {
            int diff = arr[i+1]-arr[i];
            if(abs(mindist)>abs(diff)) mindist = diff;
            if(abs(other) < abs(diff)) {
                other = diff;
                missing = arr[i];
            }
        }
        return missing+mindist;
    }
};