#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N =1e5+10;
int p[N];
int n,m;


//路径压缩和保存路径
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    
    return p[x];
}
int main(){
    scanf("%d%d",&n,&m);
    
    for(int i=1;i<=n;i++) p[i]=i;
    
    char op[2];
    int a,b;
      
    for(int i=0;i<m;i++){
        scanf("%s%d%d",op,&a,&b);
        if(op[0] == 'M') p[find(a)]=find(b);
        else{
            if(find(a) == find(b)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    
}