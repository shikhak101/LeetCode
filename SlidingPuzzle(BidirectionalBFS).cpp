class Solution {
public:
    int get1D(int i, int j, int n, int m){
        return i*m+j;
    }
    pair<int,int> get2D(int x, int n, int m){
        int i = x/m;
        int j = x%m;
        return {i,j};
    }
    int getZero(string s){
        for(int i=0; i<s.length(); i++){
            if(s[i] == '0') return i;
        }
        return -1;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        string end = "123450";
        string start = "";
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                start += to_string(board[i][j]);
            }
        }
        if(start == end) return 0;
        vector<int> dirs = {0,1,0,-1,0};
        queue<string> q1;
        queue<string> q2;
        q1.push(start);
        q2.push(end);
        map<string,int> vis1;
        map<string,int> vis2;
        vis1.insert({start,0});
        vis2.insert({end,0});
        while(!q1.empty() && !q2.empty()){
            string curr1 = q1.front();
            string curr2 = q2.front();
            q1.pop();
            q2.pop();
            if(vis2.find(curr1)!=vis2.end()){
                return vis1[curr1]+vis2[curr1];
            }
            if(vis1.find(curr2)!=vis1.end()){
                return vis1[curr2]+vis2[curr2];
            }
            int loc1 = getZero(curr1);
            int loc2 = getZero(curr2);
            pair<int,int> loc2D1 = get2D(loc1,n,m);
            pair<int,int> loc2D2 = get2D(loc2,n,m);
            int u1 = loc2D1.first;
            int v1 = loc2D1.second;
            int u2 = loc2D2.first;
            int v2 = loc2D2.second;
            for(int k = 0; k<4; k++){
                int a = u1+dirs[k];
                int b = v1+dirs[k+1];
                if(a<n && b<m && a>=0 && b>=0){
                    string t = curr1;
                    int nloc = get1D(a,b,n,m);
                    swap(t[loc1],t[nloc]);
                    if(vis1.find(t)==vis1.end()){
                        q1.push(t);
                        vis1.insert({t,vis1[curr1]+1});
                    }
                }
            }
            for(int k = 0; k<4; k++){
                int a = u2+dirs[k];
                int b = v2+dirs[k+1];
                if(a<n && b<m && a>=0 && b>=0){
                    string t = curr2;
                    int nloc = get1D(a,b,n,m);
                    swap(t[loc2],t[nloc]);
                    if(vis2.find(t)==vis2.end()){
                        q2.push(t);
                        vis2.insert({t,vis2[curr2]+1});
                    }
                }
            }
        }
        return -1;
    }
};