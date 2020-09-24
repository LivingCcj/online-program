#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<stack>
using namespace std;

vector<int> split(string str){
    const char* tmp=",[]";
    vector<int> res;
    char* p=strtok((char *)str.c_str(),tmp);
    while(p){
        res.push_back(atoi(p));
        cout<<atoi(p)<<endl;
        p=strtok(nullptr,tmp);
    }
    return res;
    
}

int main(){
    string str;
    cin>>str;

    vector<int> data,arr1,arr2;
    data=split(str);
    int len=data.size();
    if(len!=(len/2*2){
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<data.size();i++){
        if(data[i]<=0){
            cout<<0<<endl;
            return 0;
        }
        if(i<data.size()/2){
            arr1.push_back(data[i]);
        }else{
            arr2.push_back(data[i]);
        }
    }
    stack<int> s;
    long long sum=0;
    long long ans=0;
    for(int i=0;i<arr1.size();i++){
        if(s.empty() || arr2[s.top()]<=arr2[i]){
            s.push(i);
        }
        else{
            int p=s.top();
            if(s.empty()){
                sum=arr2[p]*(i-p);
            }else{
                sum=arr2[p]*(i-p-1);
            }
        }
        if(sum>=max){
            
        }
    }
    return 0;
}