#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<string.h>
using namespace std;

int main(){
    vector<string> data;
    for(int i=0;i<10;i++){
        char tmp=i+'A';
        cout<<tmp<<endl;
        data.push_back(to_string(tmp));
    }
    for(string str:data){
        cout<<str<<" "<<endl;
    }
    data.erase(data.end());
    for(string str:data){
        cout<<str<<" "<<endl;
    }
}