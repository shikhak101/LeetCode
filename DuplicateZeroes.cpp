class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        queue<int> q;
        for(int i=0; i<arr.size(); i++) {
            q.push(arr[i]);
        }
        for(int i=0; i<arr.size(); i++) {
            int c = q.front(); q.pop();
            if(c==0) {
                arr[i] = c; 
                if(i<arr.size()-1) {
                    arr[i+1] = c;
                    i++;
                }
            }
            else {
                arr[i] = c;
            }
        }
    }
};