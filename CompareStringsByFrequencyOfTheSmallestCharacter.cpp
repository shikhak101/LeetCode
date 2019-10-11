class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> fq(queries.size(),0);
        vector<int> fw(words.size(),0);
        for(int i=0; i<queries.size(); i++) {
            string q = queries[i];
            int count = 1; char c=q[0];
            for(int j = 1; j<q.length(); j++) {
                if(c>q[j]){
                    c = q[j];
                    count = 1;
                }
                else if(c == q[j]) count++;
            }
            fq[i] = count;
        }
        for(int i=0; i<words.size(); i++) {
            string w = words[i];
            int count = 1; char c=w[0];
            for(int j = 1; j<w.length(); j++) {
                if(c>w[j]){
                    c = w[j];
                    count = 1;
                }
                else if(c == w[j]) count++;
            }
            fw[i] = count;
        }
        vector<int> ans;
        for(int i=0; i<fq.size(); i++) {
            int count = 0;
            for(int j=0; j<fw.size(); j++) {
                if(fq[i]<fw[j]) count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};