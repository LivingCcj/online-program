#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;


vector<int> flag(200,0);
vector<int> split(string str){
    vector<int> res;
    const char* tmp=" ";
    char *p=strtok((char*)str.c_str(),tmp);
    while(p){
        res.push_back(atoi(p));
        p=strtok(NULL,tmp);
    }
    return res;

}

void printTree(vector<int> v,int i,int size){
    //printTree(v,i*2+1);
    cout<<"result"<<endl;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> data(n,vector<int>(m));
    int in1,in2;
    int index=0;
    while (n--)
    {
        cin>>in1>>in2;
        data[index][0]=in1;
        data[index][1]=in2;
        index++;
    }
    

    for(int i=0;i<data.size();i++){
        for(int j=0;j<data[0].size();j++){
            cout<<data[i][j]<<endl;
        }
        
    }

}