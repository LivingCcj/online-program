#include<bits/stdc++.h>

using namespace std;

/*
3
3 3
###
#@*
***
3 4
####
#@.*
**.*
3 3
.#.
#@#
.#.
*/
vector<vector<int>> step={{1,0},{-1,0},{0,1},{0,-1}};
int resMin=10000009;
// int visit[1005][1005];
// int flag=0;
void dfs(vector<vector<int>> &data,int s,int t,int count){

    if(s==0 || t==0 || (s==data.size()-1) || (t==data[0].size()-1)){
        resMin=min(resMin,count);
        return;
    }
    for(int i=0;i<4;i++){
        int newx=s+step[i][0];
        int newy=t+step[i][1];
        
        if(newx>=0 && newy>=0 && newx<data.size() && newy<data[0].size()){
            int mark = data[newx][newy];
            if (mark == 2)
            {
                continue;
            }
            if (mark == 1)
            {
                // flag=1;
                count++;
                data[newx][newy]=2;
                dfs(data,newx,newy,count);
            }else{
                data[newx][newy]=2;
                dfs(data,newx,newy,count);
            }
            data[newx][newy]=mark;
        }
    }
    return ;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> data(n,vector<int>(m,0));
        string str;
        
        int startx=-1;
        int starty=-1;
        for(int i=0;i<n; i++){
            cin>>str;
            for(int j=0;j<str.size();j++){
                if(str[j]=='#'){
                    data[i][j]=2; // 2表示q障碍
                }else if(str[j] == '*'){
                    data[i][j]=1;   // 2表示r障碍
                }else if(str[j] == '.'){
                    data[i][j]=0; 
                }else{
                    startx=i;
                    starty=j;
                    data[i][j]=0;
                }
            }
        }
    
        
        
        dfs(data,startx,starty,0);
        // data[startx][starty]=0;
        
        if(resMin==10000009){
            cout<<"-1"<<endl;
        }
        else{
                cout<<resMin<<endl;
        }
        // data[startx][starty]=2;
       
    }

    return 0;
}

