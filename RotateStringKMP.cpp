class Solution {
public:
    vector<int> generateArr(string B) {
        vector<int> arr(B.length(),0);
        int i = 0; int j = 0;
        arr[j] = 0; j++;
        while(j<B.length()) {
            int found = 0;
            if(B[i] == B[j]) {
                arr[j] = i+1;
                i++; j++;
            }
            else {
                if(i<=0) {
                    arr[j] = 0;
                }
                else {
                    while(i>0 && j<B.length()) {
                        i=arr[i-1];
                        if(B[i] == B[j]) {
                            arr[j] = i+1;
                            i++; j++;
                            found = 1;
                        }
                    }
                }
                if(found == 0) {
                    arr[j] = 0; j++;
                }
            }
        }
        return arr;
    }
    bool rotateString(string A, string B) {
        if(A.length()!=B.length()) return false;
        if(A.length() == 0) return true;
        string s = A+A;
        vector<int> arr;
        arr = generateArr(B);
        int i=0; int j = 0;
        int start = i;
        int c =0;
        while(j<B.length() && i<s.length()) {
            if(s[i] == B[j]) {
                c = 1;
                i++; j++;
                if(j == B.length()) return true;
            }
            else {
                if(i == 0){
                    i++;
                }
                else if(i>0) {
                    if(c == 1)
                    {
                        j = arr[j-1];
                        c = 0;
                        continue;
                    }
                    i++;
                }
            }
        }
        return false;
    }
};