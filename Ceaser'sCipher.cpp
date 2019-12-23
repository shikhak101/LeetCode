#include <iostream>
using namespace std;
int main() {
    int q;
    cin>>q;
    string temp;
    getline(cin,temp);
    for(int i=0; i<q; i++) {
        string S;
        string T;
        getline(cin,S);
        getline(cin,T);
        if(S.length()!=T.length()){
            cout<<-1<<endl;
            continue;
        } 
        else {
            int ch1 = S[0]-'A';
            int ch2 = T[0]-'A';
            int k = 0;
            if(ch2<ch1){
                k = 26-ch1 + ch2;
            }
            else k = ch2-ch1;
            int j;
            for(j=1; j<S.length(); j++) {
                int c1 = S[j]-'A';
                int c2 = T[j]-'A';
                int t = 0;
                if(c2<c1) {
                    t = 26-c1 + c2;
                }
                else t = c2-c1;
                if(t!=k){
                    break;
                } 
            }
            if(j==S.length()) {
                if(k<0) k = 26+k;
                cout<<k<<endl;
            }
            else cout<<-1<<endl;
        }
    }
    return 0;
}