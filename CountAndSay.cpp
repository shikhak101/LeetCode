#include<string>
class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        int count = 0;
        
        for(int i=1; i<n; i++)
        {
            string new_s = "";
            char c = s[0];
            count = 1;
            for(int j = 1; j<s.length(); j++)
            {
                if(s[j] == c) count++;
                else{
                    new_s = new_s + to_string(count) + c;
                    c = s[j];
                    count = 1;
                }
            }
            s = new_s + to_string(count) +c;
        }
        return s;
    }
};