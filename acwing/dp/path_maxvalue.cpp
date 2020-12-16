/*
 * @Description: 数字三角形 ：https://www.acwing.com/problem/content/900/
 * 
 * 从根部到达叶子节点所经历值和最大
 * 使用dp得方法
 * （1）状态表示f[i,j];,
 * （2）属性：路径和最大
 * （3）状态转移方程：dp[i][j]=max(dp[i-1][j-1]+a[i][j],dp[i-1][j]+a[i][j])
 * 时间复杂度 O(N^2)
 * @Author: ccj
 * @Date: 2020-12-15 19:45:14
 * @LastEditTime: 2020-12-15 20:13:39
 * @LastEditors:  
 */

#include<iostream>

using namespace std;

const int N=505,INF=1e9;

int a[N][N];
int dp[N][N];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
        }
    }
    
    //init 状态得初始化，
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=i+1;j++){
            dp[i][j]=-INF;
        }
    }
    dp[1][1]=a[1][1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            //状态转移方程
            dp[i][j]=max(dp[i-1][j-1]+a[i][j],dp[i-1][j]+a[i][j]); 
        }
    }
    int res=-INF;
    
    for(int j=1;j<=n;j++) res=max(res,dp[n][j]);
    cout<<res;
    return 0;
}