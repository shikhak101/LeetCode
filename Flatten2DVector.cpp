class Vector2D {
public:
    vector<vector<int>> vec;
    int i=0; int j = 0;
    Vector2D(vector<vector<int>>& v) {
        vec = v;
    }
    
    int next() {
        int res = 0;
        if(i<vec.size() && j<vec[i].size()){
            res = vec[i][j];
            if(j == vec[i].size()-1){
                i++; j = 0;
            }
            else j++;
        }
        return res;
    }
    
    bool hasNext() {
        while(i<vec.size() && vec[i].empty()) i++;
        if(i >= vec.size()) return false;
        return true;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */