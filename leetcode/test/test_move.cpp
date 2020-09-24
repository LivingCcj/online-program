#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;

int main(){
    string tmp="hello";
    vector<string> data;

    data.push_back(tmp);
    cout<<"copy tmp="<<tmp<<endl;

    // data.push_back(std::move(tmp));s
    //move == static_cast<T&&>(lValue);
    data.push_back(static_cast<string&&>(tmp));
    cout<<"move tmp="<<tmp<<endl;

    for(int i=0;i<data.size();i++){
        cout<<"data["<<i<<"]="<<data[i]<<endl;
    }
}