/*
 * @Description: 01背包问题 ：https://www.acwing.com/problem/content/2/
 * @Author: ccj
 * @Date: 2020-12-15 18:48:40
 * @LastEditTime: 2020-12-15 19:16:13
 * @LastEditors:  
 */

#include<iostream>

using namespace std;

const int N = 1e3+10;

int w[N],v[N],dp[N];
int n,V;
//01背包问题(优化版本得，只用到了一维数组)
void package1(){
    for(int i=1;i<=n;i++){
        for(int j=V;j>=v[i];j--){
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    
}

//完全背包问题（优化版本，每个物品可以无限制取）

void package2(){
    for(int i=1;i<=n;i++){
        for(int j=v[i];j<=V;j++){  //和01背包问题不同得地方
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
}

//多重背包问题 (每个物品只能取s次) 思路把每个物品拆分成多个单物品，这样可以看作是01背包问题了。

int main(){
    
    cin>>n>>V;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];

    package1();
    cout<<dp[V]<<endl;
    return 0;
    
}
