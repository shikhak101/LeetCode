class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int t = candies.size()/2;
        set<int> m;
        for(auto x:candies) {
            m.insert(x);
        }
        int s = m.size();
        t = min(t,s);
        return t;
    }
};