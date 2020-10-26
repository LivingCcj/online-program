#include<bits/stdc++.h>

using namespace std;
const int N = 5e4+10;
int p[N];
int d[N];


//主要时维护距离，当前节点和根节点的距离，然后判断mod1,2,3的情况
int find(int x){
    if(p[x] != x){
        int t=find(p[x]);
        d[x]+=d[p[x]];
        p[x]=t;
    }
    return p[x]; 
}

/**
 * link https://www.acwing.com/problem/content/242/ 
 * 
 * 并查集
 *
input 
100 7
1 101 1 
2 1 2
2 2 3 
2 3 3 
1 1 3 
2 3 1 
1 5 5

output
3

 * */



int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i]=i;

    int res=0;
    while(m--){
        int t,x,y;
        cin>>t>>x>>y;
        if(x>n || y>n){
            res++;
        }else if(t == 1){
            int px=find(x),py=find(y);
            if(px == py && (d[x]-d[y])%3!=0) res++;
            else if (px!=py){
                p[px]=py;
                d[px]=d[y]-d[x];
            }
        }else{
            int px=find(x), py=find(y);
            if(px==py && (d[x]-d[y]-1)%3!=0) res++;
            else if(px!=py){
                p[px]=py;
                d[px]=d[y]-d[x]+1;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}