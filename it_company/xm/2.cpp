#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){

    // vector<string> data{"ABCE","SFCS","ADEE"};
    vector<vector<char>> data{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string str;
    cin>>str;
    bool flag=false;
    int len=str.size();
    
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            // cout<<i<<"-"<<j<<"  "<<data[i][j]<<endl;
            if(data[i][j]==str[0] && (i+len)<=3){
                int idx=i;
                for(int k=1;k<str.size();k++){
                    idx++;
                    if(data[idx][j]==str[k]){
                        flag=true;
                    }else{
                        flag=false;
                        break;
                    }
                }
            }
            if(flag){
                cout<<"true"<<endl;
                return 0;
            }
            if(data[i][j]==str[0] && (j+len)<=4){
                int idx=j;
                for(int k=1;k<len;k++){
                    idx++;
                    if(data[i][idx]==str[k]){
                        flag=true;
                    }else{
                        flag=false;
                        break;
                    }
                }
            }
            if(flag){
                cout<<"true"<<endl;
                return 0;
            }
        }
    }

    if(len%3==0){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    
    return 0;
}