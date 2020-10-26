#include<iostream>

using namespace std;

const int N = 10;
int n;
bool col[N],dg[N],udg[N];

char flag[N][N];


/**
 * 八皇后问题
 *
 * link: https://www.acwing.com/problem/content/submission/845/ 
 * 
 * */
void dfs(int x){
    if(x == n){
        for(int i=0;i<n;i++) cout<<flag[i]<<endl;
        cout<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(!col[i] && !dg[i+x] && !udg[i-x+n]){  //不满足减支
            flag[x][i]='Q';
            col[i]=dg[i+x]=udg[i-x+n]=true;
            dfs(x+1);
            col[i]=dg[i+x]=udg[i-x+n]=false;  //回溯思想
            flag[x][i]='.';
        }
    }
    return ;
}

int main(){
    cin>>n;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            flag[i][j]='.';
        }

    dfs(0);
    return 0;
}