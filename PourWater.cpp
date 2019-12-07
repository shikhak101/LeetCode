class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        for(int i=0; i<V; i++) {
            int curr = K;
            int j = K-1;
            int l = K;
            while(j>=0 && heights[j]<=heights[curr]) {
                if(heights[j]!=heights[curr]) l = j;
                curr = j;
                j--;
            }
            if(l != K) {
                heights[l]++;
                continue;
            }
            
            curr = K;
            j = K+1;
            int r = K;
            while(j<heights.size() && heights[j]<=heights[curr]) {
                if(heights[j]!=heights[curr]) r = j;
                curr = j;
                j++;
            }
            heights[r]++;
        }
        return heights;
    }
};