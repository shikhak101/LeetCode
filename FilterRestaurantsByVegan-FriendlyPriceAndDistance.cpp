bool comp(pair<int,int> p1,pair<int,int> p2) {
    if(p1.first==p2.first){
        return p1.second > p2.second;
    }
    return p1.first>p2.first;
}
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& r, int v, int mP, int mD) {
        vector<int> res;
        if(r.size()==0) return res;
        vector<pair<int,int>> rate_id;
        for(int i=0; i<r.size(); i++ ){
            if(v==1){
                if(r[i][2] == v && r[i][3]<=mP && r[i][4]<=mD) rate_id.push_back({r[i][1],r[i][0]});
            }
            else{
                if(r[i][3]<=mP && r[i][4]<=mD) rate_id.push_back({r[i][1],r[i][0]});
            }
        }
        sort(rate_id.begin(),rate_id.end(),comp);
        for(auto x:rate_id){
            res.push_back(x.second);
        }
        return res;
    }
};