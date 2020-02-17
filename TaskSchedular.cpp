class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.size()==0) return 0;
        sort(tasks.begin(),tasks.end());
        vector<int> v(26,0);
        for(int i=0; i<tasks.size(); i++){
            v[tasks[i]-'A']++;
        }
        sort(v.begin(),v.end());
        int maxv = v[25]-1;
        int res = maxv*n;
        for(int i=24; i>=0; i--){
            if(v[i]<=0) continue;
            res -= min(maxv,v[i]);
        }
        if(res>0) return res+tasks.size();
        return tasks.size();
    }
};