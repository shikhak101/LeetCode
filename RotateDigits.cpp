class Solution {
public:
    int rotatedDigits(int N) {
        int arr[10] = {1,1,1,0,0,1,1,0,1,1};
        int res = 0;
        for(int i = 1; i<=N; i++){
            int num = i;
            int diff = 0;
            while(num>0){
                int d = num%10;
                if(arr[d] == 0) break;
                if(d==2 || d==5 || d==6 || d==9) diff++;
                num = num/10;
            }
            if(num == 0 && diff>0) res++;
        }
        return res;
    }
};