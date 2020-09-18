#include<iostream>
#include<vector>
#include<string.h>
#include<string>
using namespace std;


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

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> data(n,vector<int>(m));
    string str;
    vector<int> tmp;
    int index=0;
    getline(cin,str);
    while(n--){
        getline(cin,str);
        tmp=split(str);
        data[index++]=tmp;
    }

    int sum=0;
    int del=m%2==0 ? -1 :m/2;
    for(int i=0;i<data.size();i++){
        for(int j=0;j<data[0].size();j++){
            if(j==del){
                continue;
            }else{
                sum+=data[i][j];
            }
        }
    }
    cout<<sum<<endl;

}