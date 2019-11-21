class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        // map<string,vector<int>> pos;
        // int i=0;
        // for(auto x:words) {
        //     if(pos.find(x) == pos.end()){
        //         vector<int> t;
        //         t.push_back(i);
        //         pos.insert({x,t});
        //     }
        //     else {
        //         pos[x].push_back(i);
        //     }
        //     i++;
        // }
        // int minres = INT_MAX;
        // for(int i=0; i<pos[word1].size(); i++) {
        //     for(int j=0; j<pos[word2].size(); j++){
        //         minres = min(minres,abs(pos[word1][i]-pos[word2][j]));
        //     }
        // }
        // return minres;
        int i=-1; int j = -1;
        int minres = INT_MAX;
        for(int k = 0; k<words.size(); k++) {
            if(words[k]==word1){
                i = k;
            }
            else if(words[k] == word2) {
                j = k;
            }
            if(i>-1 && j>-1) {
                minres = min(minres,abs(i-j));
                if(minres == 1) break;
            }
        }
        return minres;
    }
};