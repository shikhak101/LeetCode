// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int res = 0;
        for(int i=1; i<n; i++) {
            if(knows(res,i)) res = i;
        }
        for(int i=0; i<n; i++) {
            if(i==res) continue;
            if(knows(i,res) == false || knows(res,i) == true) return -1;
        }
        return res;
    }
};