#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;


int resMax=-1;

vector<int> split(string &str){
    const char *tmp=" ";
    char *p=strtok((char*)str.c_str(),tmp);
    vector<int> res;
    while(p){
        res.push_back(atoi(p));
        // cout<<tStr<<endl;
        p=strtok(nullptr,tmp);
    }
    return res;

}

void  recur(vector<int> data, int total,int idx){
    if(total%7==0){
        resMax=max(total,resMax);
    }
    if(idx==data.size()){
        return;
    }
    recur(data,total+data[idx],idx+1);
    recur(data,total,idx+1);
}
int main(){
    int n;
    vector<int> data;
    string str;
    getline(cin,str);
    data=split(str);
    int len=data.size();
    for(int i=0;i<len;i++){
        recur(data,-1,i);
    }

    if(resMax==-1){
        cout<<"-1"<<endl;
    }else{
        cout<<resMax<<endl;
    }
    return 0;
} 