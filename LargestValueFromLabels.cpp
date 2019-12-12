class Comp {
    public:
    int operator() (const pair<int,int>& p, const pair<int,int>& q) {
       return p.first > q.first;
    }
};
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        int res = 0;
        unordered_map<int,priority_queue<int>> m;
        for(int i=0; i<values.size(); i++) {
            m[labels[i]].push(values[i]);
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        int sum = 0;
        for(auto x:m){
            int i=0;
            if(pq.size()==num_wanted){
                res = max(sum,res);
                sum -= pq.top();
                pq.pop();
            }
            int n = x.second.size();
            while(i<n && i<use_limit && pq.size()<num_wanted) {
                pq.push(x.second.top());
                sum+=x.second.top();
                i++;
                x.second.pop();
                if(pq.size()==num_wanted && pq.top()<x.second.top()){
                    res = max(sum,res);
                    sum -= pq.top();
                    pq.pop();
                }
            }
        }
        res = max(sum,res);
        return res;
    }
};