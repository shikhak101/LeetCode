class Solution {
public:
    int romanToInt(string s) {
        map<char,int> romans;
        romans.insert({'I',1});
        romans.insert({'V',5});
        romans.insert({'X',10});
        romans.insert({'L',50});
        romans.insert({'C',100});
        romans.insert({'D',500});
        romans.insert({'M',1000});
        int prev = 0;
        int sum = 0;
        for(int i=s.length()-1; i>=0; i--) {
            auto it = romans.find(s[i]); 
            int curr = it->second;
            if(prev>curr) sum -= curr;
            else sum += curr;
            prev = curr;
        }
        return sum;
    }
};