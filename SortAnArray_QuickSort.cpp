class Solution {
public:
    vector<int> sortArray(vector<int>& arr) {
        quickSort(arr,0,arr.size()-1);
        return arr;
    }
    void quickSort(vector<int>& arr, int l , int h) {
        if(l<h) {
            int pivot = partition(arr,l,h);
            quickSort(arr,l,pivot-1);
            quickSort(arr,pivot+1,h);
        }
    }
    int partition(vector<int>& arr, int l, int r) {
        int i=l+1;
        int j = r;
        int pivot = arr[l];
        while(i<=j) {
            while(i<=r && arr[i]<pivot) i++;
            while(j>l && arr[j] > pivot) j--;
            if(i<j) {
                swap(arr[i],arr[j]);
            }
            else {
                swap(arr[j],arr[l]);
                return j;
            }
        }
        return j;
    }
};