#include<bits/stdc++.h>
const int N=1e5+10;

int p[N];
int len[N];

using namespace std;

int find(int x){
    if(p[x] != x) p[x]=find(p[x]);
    return p[x];
}

/**
 * 
 * link: https://www.acwing.com/problem/content/839/
 * “C a b”，在点a和点b之间连一条边，a和b可能相等；
“Q1 a b”，询问点a和点b是否在同一个连通块中，a和b可能相等；
“Q2 a”，询问点a所在连通块中点的数量；
 * 
 * 
 * test
 * 
 * 
5 5
C 1 2
Q1 1 2
Q2 1
C 2 5
Q2 5

out

Yes
2
3
 * */
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        p[i]=i;
        len[i]=1;
    }
    string str;
    int a,b;
    int count=0;
    while(m--){
        cin>>str;
        if(str=="C"){
            cin>>a>>b;
            if(find(a) == find(b)) continue;
            len[find(b)]+=len[find(a)];    //合并分支前，需要更新集合大小
            p[find(a)]=find(b);
            cout<<len[find(b)]<<"  "<<len[find(a)]<<endl;

        }else if(str == "Q1"){
            cin>>a>>b;
            if(find(a) == find(b) ){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }else{
            cin>>a;
            cout<<len[find(a)]<<endl;
        }
    }
    return 0;
}