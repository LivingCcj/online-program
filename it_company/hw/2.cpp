#include<iostream>
#include<vector>
#include<string.h>
using namespace std;


int N=0;
int M=0;
void split(string str){
    const char *tmp = ",";
    char* p=strtok((char *)str.c_str(),tmp);
    int i=0;
    while(p){
        if(i==0){
            N=atoi(p);
        }else
        {
            M=atoi(p);
        }
        i++;
        p=strtok(nullptr,tmp);
    
    }
}

void getNums(vector<vector<int>> &data,int i,int j){
    if(i<0|| j<0||i>=data.size()|| j>=data[0].size() || data[i][j]==0){
        return ;
    }
    data[i][j]=0;
    getNums(data,i+1,j);
    getNums(data,i-1,j);
    getNums(data,i,j+1);
    getNums(data,i,j-1);
}

int main(){
    string nm;
    cin>>nm;
    split(nm);
    int step=N;
    string str;
    vector<vector<int>> data(N,vector<int>(M));
    int i=0;
    while(step--){
        cin>>str;
        for(int j=0;j<str.size();j++){
            if(str[j]=='S'){
                data[i][j]=1;
            }else{
                data[i][j]=0;
            }
        }
        i++;
    }
    
    int ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(data[i][j]==1){
                // cout<<i<<"  "<<j<<endl;
                ans+=1;
                getNums(data,i,j);
            }
        }
    }
    cout<<ans<<endl;

}