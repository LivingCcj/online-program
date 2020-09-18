#include<iostream>
#include<vector>
#include<limits.h>
#include<stack>
#include<algorithm>
using namespace std;

struct value{
    int index;
    int wight;
};
bool cmp(value v1,value v2){
    if(v1.wight==v2.wight){
        return v1.index<v2.index;
    }
    return v1.wight>v2.wight;
}
int main(){
    int w,l;
    cin>>w>>l;
    vector<value> data;
    int d;
    value v;
    for(int i=0;i<l;i++){
        cin>>d;
        v.index=i;
        v.wight=d;
        data.push_back(v);
    }

   
    sort(data.begin(),data.end(),cmp);
    int sum=0;
    int start=1;
    int end=0;
    int all=0;
    for(int i=0;i<data.size();i++){
        if(data[i].wight==data[i+1].wight){
            end=data[i].index;
        }
        sum=0;
        for(int j=0;j<data.size();j++){
            if(data[j].index < data[i].index && data[j].index<end && data[j].index>=start){
                sum+=(data[i].wight-data[j].wight);
            }
        }
        all+=sum;
        start=end+1;
        if(data[i].wight!=data[i+1].wight){
            break;
        }
    }
   
    int res=all*w;
    cout<<res<<endl;
    return 0;
}
