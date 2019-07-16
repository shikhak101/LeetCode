class Solution {
public:
    map<string, string> m = {{"2","abc"},{"3","def"},{"4","ghi"},{"5","jkl"},{"6","mno"},{"7","pqrs"},{"8","tuv"},{"9","wxyz"}};
    vector<string> output;
    vector<string> letterCombinations(string digits) {
        if(digits.size()<=0) return output;
        string temp = "";
        solution(digits, 0, temp);
        return output;
    }
    void solution(string digits, int index_digit, string str)
    {
        if(index_digit == digits.size()) {
            output.push_back(str);
        }
        string digit = digits.substr(index_digit,1);
        string str_digit = m[digit];
        for(char c : str_digit) {
            solution(digits, index_digit+1, str+c);
        }
    }
};