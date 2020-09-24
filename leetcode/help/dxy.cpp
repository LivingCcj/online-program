#include<iostream>
#include<vector>
using namespace std;

int getMax(vector<int> data){
    int len=data.size();
    if(len==0) return 0;
    if(len==1) return data[0];
    int pre1=0;
    int pre2=0;
    for(int i=0;i<data.size();i++){
        int tmp=max(pre2,pre1+data[i]);
        pre1=pre2;
        pre2=tmp;
    }
    return pre2;
}

int main(){
    vector<int> data{1,2,3,4,5,6};
    cout<<getMax(data)<<endl;
}