class MovingAverage {
public:
    int size;
    vector<int> q;
    /** Initialize your data structure here. */
    MovingAverage(int s) {
        size = s;
    }
    
    double next(int val) {
        q.push_back(val);
        int low = 0;
        int d;
        if(q.size()>size) {
            low = q.size()-size;
            d = size;
        }
        else d = q.size();
        int sum = 0;
        for(int i=q.size()-1; i>=low; i--) {
            sum += q[i];
        }
        return (sum*1.0)/d;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */