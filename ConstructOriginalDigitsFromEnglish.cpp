class Solution {
public:
    string originalDigits(string s) {
        string res= "";
        // vector<string> v = {zero,"one",two,three,four,five,six,seven,eight,"nine"};
        vector<string> vres(10,"");
        unordered_map<char,int> m;
        for(int i=0; i<s.length(); i++) {
            m[s[i]]++;
        }
        if(m['z']>0) {
            for(int j=0; j<m['z']; j++) 
                vres[0] += '0';
        }
        if(m['w']>0) {
            for(int j=0; j<m['w']; j++) 
                vres[2] += '2';
        }
        if(m['u']>0) {
            for(int j=0; j<m['u']; j++) 
                vres[4] += '4';
        }
        if(m['x']>0) {
            for(int j=0; j<m['x']; j++) 
                vres[6] += '6';
        }
        if(m['g']>0) {
            for(int j=0; j<m['g']; j++) 
                vres[8] += '8';
        }
        if(m['f']>0) {
            for(int j=0; j<m['f']-vres[4].length(); j++) 
                vres[5] += '5';
        }
        if(m['s']>0) {
            for(int j=0; j<m['s']-vres[6].length(); j++) 
                vres[7] += '7';
        }
        if(m['h']>0) {
            for(int j=0; j<m['h']-vres[8].length(); j++) 
                vres[3] += '3';
        }
        if(m['i']>0) {
            for(int j=0; j<m['i']-(vres[5].length()+vres[6].length()+vres[8].length()); j++) 
                vres[9] += '9';
        }
        if(m['n']>0) {
            for(int j=0; j<m['n']-(vres[7].length()+2*vres[9].length()); j++) 
                vres[1] += '1';
        }
        for(int i=0; i<10; i++) {
            res += vres[i]; 
        }
        return res;
    }
};