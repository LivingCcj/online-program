#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>> vec={{-1,0},{1,0},{0,1},{0,-1}};




int resMin=10000000;
static int END_x;
static int END_y;
void dfs(vector<vector<int>> data,int x,int y,int len){

    if(x==END_x && y==END_y) {
        resMin=min(len,resMin);
        return;
    }
    if(resMin<len){
        return;
    }
    for(int i=0;i<4;i++){
        int newx=x+vec[i][0];
        int newy=y+vec[i][1];
        if(newx>=0 && newy>=0 && newx<data.size() && newy<data.size()){
            if(data[newx][newy]==1 || data[newx][newy]==2){
                continue;
            }else{
                data[newx][newy]=2;
                dfs(data,newx,newy,len+1);
                data[newx][newy]=0;
            }
        }else{
            continue;
        }
        
    }
}

/**

5
0 1 0 3
*5#++
++#55
#5+++
@5+++
#5#++

**/
int main(){
    int n;
    cin>>n;
    vector<vector<int>> data(n,vector<int>(n));

    
    
    int startx,starty,endx,endy;
    cin>>startx>>starty>>endx>>endy;
    END_y=endx;
    END_y=endy;
    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        for(int j=0;j<str.size();j++){
            if(str[j]=='#' || str[j]=='@'){
                data[i][j]=1;
            }else{
                data[i][j]=0;
            }
        }
    }

    dfs(data,startx,starty,0);

    cout<<resMin<<endl;

    
}