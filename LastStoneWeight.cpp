class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> h;
        for(int i=0; i<stones.size(); i++) {
            h.push(stones[i]);
        }
        while(h.size()>1) {
            int max1 = h.top();
            h.pop();
            int max2 = h.top();
            h.pop();
            if(max1!=max2) {
                h.push(max1-max2);
            }
        }
        if(h.size() == 1) return h.top();
        return 0;
    }
};