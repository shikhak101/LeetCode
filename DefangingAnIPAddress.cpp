class Solution {
public:
    string defangIPaddr(string address) {
        for(int i=0; i<address.length(); i++){
            if(address[i] == '.') {
                address = address.substr(0,i) + "[.]" + address.substr(i+1, address.length()-i);
                i = i+2;
            }
        }
        return address;
    }
};