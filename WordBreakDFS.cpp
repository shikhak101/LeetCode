class Solution {
public:
    string str;
    vector<string> v;
    bool helper(string curr){
        if(curr==str) return true;
        bool b = false;
        if(curr.length()<str.length()){
            for(int i=0; i<v.size(); i++){
                string temp = curr + v[i];
                if(temp==str.substr(0,temp.length())){
                    string prev = temp;
                    string temp2 = temp;
                    while(temp2 == str.substr(0,temp2.length())){
                        prev = temp2;
                        temp2 += temp;
                    }
                    b = helper(prev);
                }
                if(b==true) return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        str = s;
        v = wordDict;
        string curr = "";
        return helper(curr);
    }
};