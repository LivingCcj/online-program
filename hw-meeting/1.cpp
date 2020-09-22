#include<iostream>

#include<string>
#include<vector>

using namespace std;


int visit[10005]={0};
string data;
vector<string> res; 


void reCur(string &str,int k){

    if(k==str.size()){
        res.push_back(data);
        data.clear();
        return;
    }
    for(int i=0;i<str.size();i++){
        if(visit[i]==0){
            visit[i]=1;
            data.append(to_string(str[i]));
            reCur(str,k+1);
            
        }
        visit[i]=0;
    }
}


vector<string> paiLine(string &str){
    int len=str.size();
    if(len==0){
        return res;
    } 
    reCur(str,0);
    return res;
}

int main(){
    string str;
    cin>>str;
    vector<string> v;
    v=paiLine(str);
    for(string str:v){
        cout<<str<<endl;
    }

}