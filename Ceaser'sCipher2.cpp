#include <iostream>
using namespace std;
int main() {
    string s;
    getline(cin,s);
    int k;
    cin>>k;
    k = k%26;
    for(int i=0; i<s.length(); i++) {
        int pos = s[i] - 'a';
        int newpos=0;
        int t = k;
        if(26-pos<k){
            t = t-(26-pos);
            s[i]='a';
        }
        newpos = t;
        s[i] = s[i]+newpos;
    }
    cout<<s<<endl;
    return 0;
}