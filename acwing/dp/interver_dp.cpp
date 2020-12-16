/*
 * @Description: 区间dp问题：石子合并 ：https://www.acwing.com/problem/content/284/
 * 
 * 状态表示dp[i][j] 表示i到j区间内的消耗体力的最小值
 * 状态属性:最小值
 * 状态转移：dp[l][r]=min(dp[l][k]+dp[k+1][r]+s[l]-s[r-1],dp[l][r]); 是多个子区间的最小值
 * @Author: ccj
 * @Date: 2020-12-15 22:21:22
 * @LastEditTime: 2020-12-15 22:30:04
 * @LastEditors:  
 */


#include<iostream>

using namespace std;

const int N = 310;

int dp[N][N];

int s[N];
int a[N];
int main(){
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++) {
        cin>>s[i];
        
    }
    for(int i=1;i<=n;i++) s[i]+=s[i-1];
    
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int l=i,r=i+len-1;
            dp[l][r]=1e8;
            for(int k=l;k<r;k++)
            {
                int tmp=dp[l][k]+dp[k+1][r]+s[r]-s[l-1];
                dp[l][r]=min(tmp,dp[l][r]);
            }
        }
    }
    cout<<dp[1][n];
    return 0;
}