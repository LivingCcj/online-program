#include<iostream>

using namespace std;

long long deal(string str1,string str2){
    int len=str1.size();
    long long res=0;
    long long res1=0;
    long long res2=0;
    long long mul=1;
    for(int i=len-1;i>=0;i--){
        int tmp1=str1[i]-'a';
        int tmp2=str2[i]-'a';
        // if(tmp2>tmp1)
        //     res+=(tmp2-tmp1)*mul;
        // else{
           
        //     res+=res2-res1;
        // }
        res1+=(tmp1)*mul;
        res2+=(tmp2)*mul;
        mul=mul*26;
    }
    return res2-res1;
}

int main(){
    int n;
    int m;
    cin>>n;
    string str1,str2;
    string tmp;
    for(int i=0;i<n;i++){
        cin>>m>>str1>>str2;
        // cout<<m<<" "<<str1<<" "<<str2<<endl;
        int res=deal(str1,str2);
        if(res<=0){
            cout<<0<<endl;
        }else{
            cout<<res-1<<endl;
        }
    }
}