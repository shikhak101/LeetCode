class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n,0);
        stack<int> s;
        int prev = 0;
        for(int i=0; i<logs.size(); i++) {
            stringstream  data(logs[i]);
            string line;
            vector<string> logssplit;
            while(std::getline(data,line,':'))
            {
                logssplit.push_back(line);
            }
            if(logssplit[1] == "start") {
                if(!s.empty())
                    res[s.top()]+=stoi(logssplit[2])-prev;
                s.push(stoi(logssplit[0]));
                prev = stoi(logssplit[2]);
            }
            else {
                res[s.top()] += stoi(logssplit[2])-prev+1;
                prev = stoi(logssplit[2])+1;
                s.pop();
            }
        return res;
    }
};