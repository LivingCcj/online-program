#include<iostream>
#include<vector>
#include<sstream>
#include<string.h>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

// struct node_t{
//     int x;
//     int y;
//     node_t(){
//         memset(this,0,sizeof(node_t));
//     }
// };   

string combine(int x,int y){
    ostringstream oss;
    oss<<x;
    oss<<",";
    oss<<y;
    return oss.str();

}
int main(){
    string str;
    cin>>str;
    int prex=0;
    int prey=0;
    unordered_map<string,int> his;
    his[combine(prex,prey)]=1;
    string tmp;
    for(int i=0;i<str.size();i++){
        if(str[i]=='E'){
            prex=prex;
            prey=prey+1;
            tmp=combine(prex,prey);
            
            if(his.count(tmp)>0){
                cout<<"True"<<endl;
                return 0;
            }
            his[tmp]=1;
            continue;
        }
        if(str[i]=='W'){
            prex=prex;
            prey=prey-1;
            tmp=combine(prex,prey);
            if(his.count(tmp)>0){
                cout<<"True"<<endl;
                return 0;
            }
            his[tmp]=1;
            continue;
            
        }
        if(str[i]=='N'){
            prex=prex+1;
            prey=prey;
            tmp=combine(prex,prey);
            if(his.count(tmp)>0){
                cout<<"True"<<endl;
                return 0;
            }
            his[tmp]=1;
            continue;
        }
        if(str[i]=='S'){
            prex=prex-1;
            prey=prey;
            tmp=combine(prex,prey);
            if(his.count(tmp)>0){
                cout<<"True"<<endl;
                return 0;
            }
            his[tmp]=1;
            continue;
        }
    }
    cout<<"False"<<endl;
    return 0;

}