#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;


bool isPlalin(string &str){
    int len=str.size();
    if(len==1){
        return true;
    }
    int i=0;
    int j=len-1;
    bool flag=true;
    while(i<j){
        if(str[i++]!=str[j--]){
            flag=false;
            break;
        }
    }
    return flag;

}

vector<vector<string>> record;

void getResult(string &str,int s,vector<string> data){
    
    if(s==str.size()){
        record.push_back(data);
        return;
    }
    for(int i=1;i<=str.size()-s;i++){
        string sTmp=str.substr(s,i);
        if(isPlalin(sTmp)){
            data.push_back(sTmp);
            getResult(str,s+i,data);
            data.erase(data.end());
        }
    }
}
int main(){
    string str;
    cin>>str;
    if(str.empty()){
        cout<<"error input"<<endl;
    }
    vector<string> data;
    getResult(str,0,data);

    int len=record.size();
    ostringstream oss;
    cout<<'['<<endl;
    for(int i=0;i<len;i++){
        oss<<" [";
        for(int j=0;j<record[i].size();j++){
            oss<<'\"'<<record[i][j]<<'\"';
            if(j==record[i].size()-1){
                oss<<']';
            }else{
                oss<<',';  
            }
        }
        if(i!=len-1){
            oss<<',';
        }
        string tmp=oss.str();
        cout<<tmp<<endl;
        oss.str("");
    }
    cout<<']'<<endl;
    return 0;

}