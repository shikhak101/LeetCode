class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t new_n;
        for(int i=0; i<32; i++){
            new_n = (new_n << 1) + (n & 1);
            n = n >> 1;
        }
        return new_n;
    }
};