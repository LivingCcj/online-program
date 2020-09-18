#include<iostream>
#include<string>
using namespace std;

long long res=0;
const int md=1000000007;
void recr(string &str){
    bool rr=true;
    for(int i=0;i<str.size();i++){
        if(str[i]!='*'){
            rr=false;
        }
    }   
    if(rr){
        // cout<<res<<endl;
        res=(res+1)%md;
        return;
    }
    for(int i=0;i<str.size();i++){
        if(str[i]=='1'){
        str[i]='*';
        bool f1=false;
        bool f2=false;

        if((i-1)>=0 && str[i-1]!='*'){
            if(str[i-1]=='1') {str[i-1]='0';}
            else if(str[i-1]=='0') {str[i-1]='1';}
            f1=true;
        }
        if((i+1)<=str.size()-1 && str[i+1]!='*'){
            if(str[i+1]=='1') {str[i+1]='0';}
            else if(str[i+1]=='0') {str[i+1]='1';}
            f2=true;
        }
        recr(str);

        if(f1){
            if(str[i-1]=='0') {str[i-1]='1';}
            else  {str[i-1]='0';}
        }
        if(f2){
            if(str[i+1]=='0') {str[i+1]='1';}
            else  {str[i+1]='0';}
        }

        str[i]='1';
        }
    }

}
int main(){

    int n;
    cin>>n;
    string str;
    while(n--){
        cin>>str;

        if(str.find('1')!=string::npos){
            recr(str);
            cout<<res<<endl;
            res=0;
        }else{
            cout<<0<<endl;
        }

    }
    return 0;
}
