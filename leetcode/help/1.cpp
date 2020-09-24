#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<limits.h>
using namespace std;

vector<int> split(string str){
    const char* tmp=" ";
    char *p=strtok((char *)str.c_str(),tmp);
    vector<int> res;
    while(p!=nullptr){
        res.push_back(atoi(p));
        p=strtok(NULL,tmp);
    }
    return res;
}


int main(){
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    cout<<str1<<" " <<str2<<endl;
    vector<int> a1=split(str1);
    vector<int> a2=split(str2);
    vector<int> res1;
    vector<int> res2;
    for(int i=0;i<a2.size();i++){
        for(int j=0;j<a1.size();j++){
            if(a2[i]==a1[j]){
                res1.push_back(a2[i]);
                a1[j]=INT_MAX;
            }
        }
    }
    for(int i=0;i<a1.size();i++){
        if(a1[i]!=INT_MAX){
            res2.push_back(a1[i]);
        }
    }
    sort(res2.begin(),res2.end());
    for(int i=0;i<res1.size();i++){
        cout<<res1[i]<<" ";
    }
    for(int i=0;i<res2.size()-1;i++){
        cout<<res2[i]<<" ";
    }
    cout<<res2[res2.size()-1]<<endl;
}