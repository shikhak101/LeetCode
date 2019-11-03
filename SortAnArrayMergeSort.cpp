class Solution {
public:
    vector<int> res;
    vector<int> sortArray(vector<int>& arr) {
        mergeSort(arr, 0, arr.size()-1);
        return arr;
    }
    void mergeSort(vector<int>& arr, int l , int r) {
        if(l<r) {
            int mid = (l+r)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
    }
    void merge(vector<int>& arr, int l, int m, int r) {
        int i = l;
        int j = m+1;
        while(i<m+1 && j<=r){
            if(arr[i]<arr[j]) {
                res.push_back(arr[i++]);
            }
            else {
                res.push_back(arr[j++]);
            }
        }
        while(i<m+1) res.push_back(arr[i++]);
        while(j<=r) res.push_back(arr[j++]);
        int p = 0;
        for(int k = l; k<=r; k++) {
            arr[k] = res[p++];
        }
        res.clear();
    }
};