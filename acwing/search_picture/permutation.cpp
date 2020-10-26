#include<iostream>
#include<vector>

using namespace std;


//全排列，不需要 额外的空间
void dfs(vector<int> &data,int i){
    if(i==data.size()){
        for(int k=1;k<i-1;k++){
            cout<<data[k]<<" ";
        }
        cout<<data[i-1]<<endl;
        return ;
    }else{
        for(int j=i;j<data.size();j++){
            swap(data[i],data[j]);
            dfs(data,i+1);
            swap(data[i],data[j]);
        }
    }

}

const int N =10;

int path[N];
bool st[N];
int n;
//全排列，需要 额外的空间
void dfs2(int u){
    if(u == n){
        for(int k=0;k<n;k++){
            cout<<path[k]<<" ";
        }
        cout<<endl;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!st[i]){
            path[u]=i;
            st[i]=true;
            dfs2(u+1);
            st[i]=false;
        }
    }
}
int main(){
    cin >>n;
    // vector<int> data(n+1);
    // for(int i=1;i<=n;i++){
    //     data[i]=i;
    // }

    dfs2(0);

    
}