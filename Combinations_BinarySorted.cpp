class Solution {
public:
    vector<vector<int>> res;
    vector<int> eachres;
    vector<vector<int>> combine(int n, int k) {
        for(int i=1; i<k+1; i++) {
            eachres.push_back(i);
        }
        eachres.push_back(n+1);
        int j = 0; 
        while(j<k) {
            vector<int> temp= eachres;
            temp.pop_back();
            res.push_back(temp);
            j=0;
            while(j<k && eachres[j]+1 == eachres[j+1]) {
                eachres[j] = j+1;
                j++;
            }
            eachres[j] = eachres[j]+1;
            
        }
        return res;
    }
};