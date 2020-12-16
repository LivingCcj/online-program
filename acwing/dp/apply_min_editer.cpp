/*
 * @Description: 最短距离的应用：https://www.acwing.com/problem/content/901/
 * 
 * 主要是设计一些字符串操作，strlen(), 二维字符串的输入，
 * @Author: ccj
 * @Date: 2020-12-15 21:52:03
 * @LastEditTime: 2020-12-15 21:53:06
 * @LastEditors:  
 */


#include<iostream>
#include<string.h>
using namespace std;

const int N = 1010;

char a[N][N],q[N];


int dp[N][N];
int ed(char st1[],char st2[]){
    int l1=strlen(st1+1);
    int l2=strlen(st2+1);
    for(int i=1;i<=l1;i++) dp[i][0]=i;
    for(int j=1;j<=l2;j++) dp[0][j]=j;
    
    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1);
            dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(st1[i]!=st2[j]));
            
        }
    }
    return dp[l1][l2];
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i]+1;
    int cn;
    while(m--){
        cin>>q+1>>cn;
        int res=0;
        for(int i=1;i<=n;i++){
            if(ed(a[i],q)<=cn){
                res++;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}