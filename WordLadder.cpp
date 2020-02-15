class Solution {
public:
    int diff(string s1, string s2){
        int d = 0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]!=s2[i]) d++;
        }
        return d;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        if(n==0) return 0;
        vector<int> vis(n,0);
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            string curr = q.front().first;
            int l = q.front().second;
            if(curr == endWord) return l;
            q.pop();
            for(int i=0; i<n; i++){
                if(vis[i]==1) continue;
                if(diff(curr,wordList[i]) == 1){
                    q.push({wordList[i],l+1});
                    vis[i] = 1;
                }
            }
        }
        return 0;
    }
};