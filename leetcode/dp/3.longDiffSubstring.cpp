#include<iostream>
#include<set>
#include<string>
using namespace std;

int main(){
    string str;
    cin>>str;
    int len=str.size();
    set<char> data; 
    int rx=-1;
    int resMax=0;
    for(int i=0;i<len;i++){
        if(i>0){
            data.erase(str[i-1]);
        }
        while(rx+1<len && data.count(str[rx+1])==0){
            data.insert(str[rx+1]);
            rx++;
        }
        resMax=max(resMax,rx-i+1);
    }
    
    cout<<resMax<<endl;
    return 0;
}