#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Link{
    int u;
    int v;
};
int visit[100005];
void dfs(int k,int target,vector<vector<int>> arr){
    if(k==target){
        return;
    }
    for(int i=0;i<arr[k].size();i++){
        if(visit[arr[k][i]]==0){
            visit[arr[k][i]]=1;
            dfs(arr[k][i],target,arr);
        }
    }
}
int main(){

    int  n,m,q;
    cin>>n>>m>>q;
    Link link;
    // vector<Link> data;
    vector<vector<int>> data(n+1,vector<int>());
    int u,v;
    while(m--){
        cin>>u>>v;
        data[u].push_back(v);
        data[v].push_back(u);
    }
    vector<Link> query;
    while(q--){
        cin>>link.u>>link.v;
        query.push_back(link);
    }



    queue<int> hash;

    for(int i=0;i<query.size();i++){
        int qx=query[i].u;
        int qy=query[i].v;
        for(int k=0;k<n+1;k++){
            visit[k]=0;
        }
        
        hash.push(qx);
        int next=qx;
        int flag=0;
        while(!hash.empty()){
            if(!hash.empty()){
                next=hash.front();
                hash.pop();
            }
            if(visit[next]==1){
                continue;
            }
            visit[next]=1;
            for(int i=0;i<data[next].size();i++){
                if(data[next][i]==qy){
                    cout<<"Yes"<<endl;
                    flag=1;
                    break;
                }else{
                    if(visit[data[next][i]]!=1){
                        hash.push(data[next][i]);
                    }
                }
            }
            if(flag==1){
                break;
            }
        }
        
        // dfs(qx-1,qy-1,data);
        if(flag==0)
            cout<<"No"<<endl;
        while(!hash.empty()){
            hash.pop();
        }
    }
}