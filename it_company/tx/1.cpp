#include<iostream>
#include<string>

using namespace std;

int main(){
    string str;
    cin>>str;
    if(str.size()==0){
        cout<<0<<endl;
        return 0;
    }

    int res=0;
    for(int i=0;i<str.size();i++){
        char tmp=str[i];
        if(tmp=='0'){
            continue;
        }else{
            res++;
        }
        for(int j=i+1;j<str.size();j++){
            char tmp2=str[j];
            if(tmp=='(' && tmp2==')'){
                str[j]='0';
                res--;
                continue;
            }
            if(tmp=='[' && tmp2==']'){
                str[j]='0';
                res--;
                continue;
            }
        }
    }
    cout<<1<<endl;
    
    return 0;
}