class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        int num = n;
        while(st.find(num) == st.end()){
            st.insert(num);
            int temp = num;
            int sum = 0;
            while(temp>0){
                int d = temp%10;
                sum += (d*d);
                temp = temp/10;
            }
            num = sum;
        }
        if(num == 1) return true;
        return false;
    }
};