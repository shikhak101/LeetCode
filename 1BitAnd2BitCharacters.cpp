class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool last = false;
        for(int i=0; i<bits.size(); i++) {
            if(bits[i] == 0) {
                last = true;
            }
            else{
                last = false;
                i++;
            }
        }
        return last;
    }
};