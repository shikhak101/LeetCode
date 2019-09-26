class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int arr[n+1] = {0};
        for(int i=0; i<n; i++) {
            if(citations[i] < n) arr[citations[i]]++;
            else arr[n]++;
        }
        int total = 0;
        int i = n; 
        while(i>=0) {
            total+=arr[i];
            if(total>=i) return i;
            i--;
        }
        return i;
    }
};