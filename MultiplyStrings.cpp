class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.length();
        int m = num2.length();
        vector<int> mul(n+m,0);
        for(int i=n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                int val = (num1[i]-'0')*(num2[j]-'0');
                int sum = (val+mul[i+j+1]);
                mul[i+j+1] = sum%10;
                mul[i+j] += sum/10;
            }
        }
        int s = 0;
        while(s<mul.size()-1 && mul[s]==0){
            s++;
        }
        string res = "";
        for(int i=s; i<mul.size(); i++){
            res+=to_string(mul[i]);
        }
        return res;
    }
};