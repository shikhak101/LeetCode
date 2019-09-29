class Solution {
public:
    struct tuple{
        int x,y,val;
        public: tuple(int x, int y, int val) {
            this->x = x;
            this->y = y;
            this->val = val;
        }
    };
    struct cmp {
        bool operator()(tuple a, tuple b) {
            return a.val>b.val;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = 0;
        int col = 0;
        int n = matrix.size();
        int count = 0;
        priority_queue <tuple, vector<tuple>, cmp> pq;
        for(int i=0; i<n; i++) {
            pq.push(tuple(0,i,matrix[0][i]));
        }
        for(int i=0; i<k-1; i++){
            tuple t = pq.top();
            pq.pop();
            if(t.x == n-1) continue;
            pq.push(tuple(t.x+1,t.y,matrix[t.x+1][t.y]));
        }
        return pq.top().val;
    }
};