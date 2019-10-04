class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        for(int i=1; i<=6; i++) {
            int rotA = 0; 
            int rotB = 0;
            int comm = 0;
            for(int j = 0; j<A.size();j++) {
                if(A[j] == i) rotA++;
                if(B[j] == i) rotB++;
                if(A[j] == i && B[j] == i) comm++;
            }
            if(rotA+rotB-comm == A.size()) {
                if(rotA<rotB) return rotA-comm;
                return rotB-comm;
            }
        }
        return -1;
    }
};