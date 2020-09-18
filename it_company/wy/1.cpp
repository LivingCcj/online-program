#include<iostream>
#include<vector>
#include<string>
#include<string.h>

using namespace std;

static vector<string> res;
static vector<vector<string>> data;

void split(string &str){
    const char *tmp=" ";
    char *p=strtok((char*)str.c_str(),tmp);
    vector<string> res;
    while(p){
        string tStr(p);
        res.push_back(tStr);
        // cout<<tStr<<endl;
        p=strtok(nullptr,tmp);
    }
    data.push_back(res);
    return ;
}


static void getRes(vector<vector<string>> &data,int idx,string str){
    if(idx==data.size()) {
        string tmp=str.substr(0,str.size()-1);
        // cout<<tmp<<endl;
        res.push_back(tmp);
        return;
    }
    vector<string> tmp=data[idx];
    for(int i=0;i<tmp.size();i++){
        getRes(data,idx+1,str.append(tmp[i]).append("-"));
        str =str.substr(0,str.size()-tmp[i].size()-1);
        // cout<<str<<endl;
    }

}
int main(){ 
    int n;
    
    string str;
    getline(cin,str);
    n=atoi(str.c_str());
    cout<<n<<endl;

    vector<string> tmp;
    for(int i=0;i<n;i++){
        getline(cin,str);
        split(str);
    }
    string tStr="";
    cout<<data.size()<<endl;
    cout<<data[2][1]<<endl;
    // return 0;

    if(n==1){
        for(int i=0;i<data[1].size();i++){
            cout<<data[1][i]<<endl;
        }
        return 0;
    }
    getRes(data,0,tStr);

    if(n)
    for(int i=0;i<res.size();i++ ){
        cout<<res[i]<<endl;
    }
    return 0;
    
}