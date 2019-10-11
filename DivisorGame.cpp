class Solution {
public:
    bool divisorGame(int N) {
        if(N<=1) return false;
        int step = 1;
        return solution(N,step);
    }
    bool solution(int N, int& step) {
        if(N == 1 && step%2 == 0) {
            return true;
        }
        else if(N==1 && step%2 == 1) return false;
        for(int x=1; x<N; x++) {
            
            if(N%x == 0) {
                return solution(N-x, ++step);
            }
        }
        return false;
    }
};