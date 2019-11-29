class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people,0);
        int i=1;
        while(candies>0) {
            int loc = (i-1)%num_people;
            if(candies < i) {
                res[loc] += candies;
                break;
            }
            res[loc] += i;
            candies -= i;
            i++;
        }
        return res;
    }
};