#include<iostream>
#include<vector>
#include<string>
#include<string.h>

using  namespace std;

vector<string> split(string str){
    const char* tmp=" ";
    char *p=strtok((char*)str.c_str(),tmp);
    vector<string> res;
    while(p){
        string str=p;
        cout<<string(p)<<endl;
        res.push_back(str);
        p=strtok(nullptr,tmp);
    }
    return res;
}



int main(){

    string str;
    vector<string> data;
    int flag=0;
    bool hasNum=false;
    bool hasa=false;
    bool hasA=false;
    bool hasSig=false;

    while(cin>>str){
        if(str.size()<8 || str.size()>120){
            cout<<"1"<<endl;
            continue;
        }
        for(int i=0;i<str.size();i++){
            if( str[i]>='0' && str[i]<='9'){
                hasNum=true;
                continue;
            }
            if(str[i]>='a' && str[i]<='z'){
                hasa=true;
                continue;
            }
            if(str[i]>='A' && str[i]<='Z'){
                hasA=true;
                continue;
            }
            hasSig=true;
            
        }
        if(hasSig && hasa && hasA && hasNum){
            cout<<"0"<<endl;
        }else{
            cout<<"2"<<endl;
        }
        bool hasNum=false;
        bool hasa=false;
        bool hasA=false;
        bool hasSig=false;
    }
    return 0;
}