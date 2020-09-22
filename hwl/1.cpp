#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


char res[25];
int main(){

    int n,m;
    cin>>n;
    cin>>m;
    string str;
    cin>>str;
    long long sum=0;
    int len=str.size();
    long fator=1;
    int tmp=0;
    for(int i=len-1;i>=0;i--){
        if(str[i]<='9' && str[i]>='0'){
            tmp=str[i]-'0';
        }else{
            tmp=str[i]-'A'+10;
        }
        sum=sum+fator*tmp;
        fator*=n;
    } 
    int j=0;
    int flag=0;
    while(sum>0){
        tmp=sum%m;
        sum=sum/m;
        if(tmp<=9){
           res[j++]='0'+tmp; 
        }else{
            res[j++]='A'+tmp-10;
        }
    }
    res[j]='\0';
    string out(res);
    reverse(out.begin(),out.end());
    cout<<out<<endl;
}