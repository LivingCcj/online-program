#include<iostream>
#include<vector>
#include<string.h>
using namespace std;


void split(string str,vector<int> &res){
    const char* tmp=",";
    char *p= strtok((char*)str.c_str(),tmp);
    while(p){
        int ans=atoi(p);
        res.push_back(ans);
        p=strtok(nullptr,tmp);
    }
    return;
}


int dp[10005];
int main(){
    int m;
    cin>>m;
    vector<int> data;

    string str;
    cin>>str;

    split(str,data);

    // for(int a:data){
    //     cout<<a<<endl;
    // }
    dp[0]=1;
    for(int v:data){
        for(int i=v;i<=m;i++){
            dp[i]=dp[i-v]+dp[i];
        }
    }
    cout<<dp[m]<<endl;
    return 0;

    
}