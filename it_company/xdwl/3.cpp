#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    string str;
    vector<string> data(n);
    for(int i=0;i<n;i++)
    {
        cin>>str;
        data[i]=str;
    }
    for(int i=0;i<n;i++){
        cout<<data[i]<<endl;
    }
    return 0;
}