/*
 * @Description: 差分：https://www.acwing.com/problem/content/799/
 * 主要用到了差分思想，计算l~R之间加C的结果。
 * 
 * 输入样例：
6 3
1 2 2 1 2 1
1 3 1
3 5 1
1 6 1
输出样例：
3 4 5 3 4 2
 * @Author: ccj
 * @Date: 2020-12-12 15:22:19
 * @LastEditTime: 2020-12-12 15:24:21
 * @LastEditors:  
 */


#include<iostream>

using namespace std;

const int N=100010;

int n,m;
int a[N],b[N];

//更新差分数组
int insert(int l,int r,int c){
    b[l]+=c;
    b[r+1]-=c;
}
int main(){
    int n,m;
    cin>>n>>m;
    
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) insert(i,i,a[i]);
    
    while(m--){
        int l,r,c;
        cin>>l>>r>>c;
        insert(l,r,c);
    }
    for(int i=1;i<=n;i++) b[i]+=b[i-1];
    for(int i=1;i<=n;i++) cout<<b[i]<<" ";
}
