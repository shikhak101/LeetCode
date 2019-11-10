class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        vector<int> v2;
        string word = "";
        for(int i =0;i<version1.length(); i++){
            if(version1[i] == '.') {
                v1.push_back(stoi(word));
                word = "";
            }
            else {
                word+=version1[i];
            }
        }
        v1.push_back(stoi(word));
        word = "";
        for(int i =0;i<version2.length(); i++){
            if(version2[i] == '.') {
                v2.push_back(stoi(word));
                word = "";
            }
            else {
                word+=version2[i];
            }
        }
        v2.push_back(stoi(word));
        
        int i=0; 
        while(i<v1.size() && i<v2.size()) {
            if(v1[i] > v2[i]) return 1;
            if(v1[i] < v2[i]) return -1;
            i++;
        }
        while(i<v1.size() && v1[i] == 0) i++;
        while(i<v2.size() && v2[i] == 0) i++;
        if(i<v1.size()) return 1;
        if(i<v2.size()) return -1;
        return 0;
    }
};