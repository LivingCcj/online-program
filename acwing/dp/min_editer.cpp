/*
 * @Description: 最短编辑距离：https://www.acwing.com/problem/content/904/
 * 
 * 状态表示 dp[i][j] 表示a前i个字符和b前j个字符匹配的最少编辑距离。
 * 
 * 考虑三种转移状态：增，闪，改
 * @Author: ccj
 * @Date: 2020-12-15 21:19:16
 * @LastEditTime: 2020-12-15 21:28:11
 * @LastEditors:  
 */

#include<iostream>
using namespace std;

const int N = 1010;

char st1[N],st2[N];

int dp[N][N];


int main(){
    int n,m;
    cin>>n>>st1+1>>m>>st2+1;

    //init
    for(int i=0;i<=n;i++) dp[i][0]=i;
    for(int i=0;i<=m;i++) dp[0][i]=i;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1])+1;  //增加或者删除操作
            if(st1[i]==st2[j]){
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]);//更新操作
            }else{
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}