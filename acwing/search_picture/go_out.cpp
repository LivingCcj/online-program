#include<bits/stdc++.h>

using namespace std;
const int N=105;

int maps[N][N];
int resMin=INT_MAX;
int n,m;
// int[][] step={{1,0},{-1,0},{0,1},{0,-1}};
// void dfs(int r,int c,int res){
//     if(r==n && c==m){
//         resMin=min(resMin,res);
//         return;
//     }
//     for(int i=0;i<4;i++){
//         int nx=r+step[i][0];
//         int ny=r+step[i][1];
//         if(nx>=0 && nx<n && ny>=0 && ny <m && maps[nx][ny]==0){
//             maps[nx][ny]=1;
//             bfs(nx,ny,res+1);
//             maps[nx][ny]=0;
//         }
//     }

// }

struct node{
    int x;
    int y;
    node(int nx,int ny):x(nx),y(ny){}
};
queue<node> q;

// int g[N][N];
int d[N][N];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};



int bfs(){
    memset(d,-1,sizeof d);
    d[0][0]=0;
    node pp(0,0);
    q.push(pp);
    while(!q.empty()){
        node tmp=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=tmp.x+dx[i];
            int ny=tmp.y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny <m &&maps[nx][ny]==0 && d[nx][ny]==-1){
                d[nx][ny]=d[tmp.x][tmp.y]+1;
                node nn(nx,ny);
                q.push(nn);
            }            
        }        
    }
    return d[n-1][m-1];
}


int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>maps[i][j];
    

    // bfs(0,0,0);
    // cout<<resMin<<endl;
    cout<<bfs()<<endl;
    return 0;
}