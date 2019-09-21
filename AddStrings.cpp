class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        string res = "";
        int i = num1.size()-1;
        int j = num2.size()-1;
        while(i>=0 || j>=0 || carry>0) {
            int n1 = 0; 
            int n2 = 0;
            if(i>=0) n1 = num1[i] - '0';
            if(j>=0) n2 = num2[j] - '0';
            int n3 = n1 + n2 + carry;
            res = to_string(n3%10) + res;
            carry = n3/10;
            i--;
            j--;
        }
        return res;
    }
};