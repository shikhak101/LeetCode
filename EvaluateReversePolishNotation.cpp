class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        set<string> operators= {"+","-","*","/"};
        for(int i=0; i<tokens.size(); i++){
            if(operators.find(tokens[i]) != operators.end()) {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                int res = 0;
                if(tokens[i] == "+")
                    res = num1 + num2;
                else if(tokens[i] == "-")
                    res = num2 - num1;
                else if(tokens[i] == "*")
                    res = num1 * num2;
                else if(tokens[i] == "/")
                    res = num2 / num1;
                st.push(res);
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};