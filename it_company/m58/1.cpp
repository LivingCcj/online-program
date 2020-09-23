#include<bits/stdc++.h>

using namespace std;
//"1 + 2 * 3"

int calculate(string input) {
    int len=input.size();
    int neg=1;
    int res=0;
    for(int i=0;i<len;i++){
        if(input[i]=='-'){
            neg=-1;
        }
        if(input[i]>='0' && input[i]<='9'){
            int tmp=input[i]-'0';
            res=res*10+tmp;
        }
    }
    return res*neg;
}

int main(){
    string str;
    getline(cin,str);
    cout<<calculate(str)<<endl;
}