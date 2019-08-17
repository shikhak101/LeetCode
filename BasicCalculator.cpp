class Solution {
public:
    int calculate(string s) {
       return solution (s, 0);
    }
    int i = 0;
    int solution(string s, int idx)
    {
        i = idx;
        char op = '+';
        int result = 0;
        int d= 0;
        while(i<s.length())
        {   
            // cout<<"result = "<<result<<"\n";
            if(isdigit(s[i]))
            {
                int d1 = s[i] - '0';
                d = (d * 10) + d1;
            }
            else if(s[i] == '+' || s[i] == '-'){
                if(op == '+') result += d;
                else if (op == '-') result -= d;
                op = s[i];
                d = 0;
            }
            else if(s[i] == '(') {
                if(op == '+') result += solution(s,i+1);
                else if (op == '-') result -= solution(s, i+1);
                d = 0;
                
            }
            else if (s[i] == ')')
            {
                if(op == '+') result += d;
                else if (op == '-') result -= d;
                d = 0;
                
                return result;
                
            }
            i++;
        }
        if(op == '+') result += d;
        else if (op == '-') result -= d;
        return result;
    }
};