class Solution {
public:
    vector<int> partitionLabels(string S) {
        int arr[26] = {0};
        vector<int> v;
        for(int i=0; i< S.size(); i++)
        {
            arr[S[i]-'a'] = i;
        }
        int m = 0, s = 0;
        for(int i=0; i<S.size(); i++)
        {
            m = max(m,arr[S[i]-'a']);
            if(i == m)
            {
                v.push_back(i-s+1);
                s = i+1;
            }
        }
        return v;
    }
};