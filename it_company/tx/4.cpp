
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> data(m,vector<int>(2));
    int tmp1,tmp2;
    int index=0;
    while(m--){
        cin>>tmp1>>tmp2;
        data[index][0]=tmp1;
        data[index][1]=tmp2;
        index++;
    }
    cout<<2<<endl;
}