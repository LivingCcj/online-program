#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
using namespace std;


struct node{
    int x;
    int y;
};
int main(){
    int n=5;
    vector<node> data(n);
    // unordered_map<node,int> his;
    map<node,int> his;
    node tmp;
    for(int i=0;i<n;i++){
        data[i].x=i+1;
        data[i].y=i+3;
    } 

    for(int i=0;i<n;i++){
        tmp.x=i+1;
        tmp.y=i+3;
        his[(const node)tmp]=1;
    } 

    for_each(data.begin(),data.end(),[](node n){cout<<n.x<<" "<<n.y<<endl;});

    cout<<"============"<<endl;

    for(auto &item:his){
        cout<<item.first<<" "<<item.second<<endl;
    }
}

