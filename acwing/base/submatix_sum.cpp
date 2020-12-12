/*
 * @Description: 子矩阵和：https://www.acwing.com/problem/content/798/
 * @Author: ccj
 * @Date: 2020-12-12 11:36:58
 * @LastEditTime: 2020-12-12 11:37:22
 * @LastEditors:  
 */


#include<iostream>

using namespace std;

const int N =1e4+10;

int a[N][N],s[N][N];

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
    }
    
    while(k--){
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        //子矩阵之和
        int sum=s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
        printf("%d\n",sum);
    }
    return 0;
    
}