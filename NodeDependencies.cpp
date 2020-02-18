#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int main(){
    // vector<vector<int> > inp;
    // [[7,11], [5,11], [3,8], [11,2], [11,9], [8,9],[3,10]] 
    int n;
    cin>>n;
    vector<vector<int> > inp;

    for(int i = 0; i< n; i++){
        int x, y;
        cin>>x>>y;
        vector<int> temp;
        temp.push_back(x);
        temp.push_back(y);
        inp.push_back(temp);
    }
    int x;
    cin>>x;
    map<int,vector<int> > m;
    for(int i=0; i<inp.size(); i++){
        m[inp[i][1]].push_back(inp[i][0]);
    }
    vector<int> res;
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        res.push_back(curr);
        if(m.find(curr)==m.end()) continue;
        for(int i=0; i<m[curr].size(); i++){
            q.push(m[curr][i]);
        }
    }
    for(int x:res){
        cout<<x<<",";
    }
    cout<<endl;
    return 0;
}