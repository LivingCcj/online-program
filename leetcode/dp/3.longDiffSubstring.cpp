#include<iostream>
#include<set>
#include<string>
#include<queue>
using namespace std;


//最长不同字串

int longDiffSubString(string str){
    int rx=-1;
    int resMax=0;
    set<char> data;
    for(int i=0;i<str.size();i++){
        if(i>0){
            data.erase(str[i-1]);
        }
        while(rx+1<str.size() && data.count(str[rx+1])==0){
            data.insert(str[rx+1]);
            rx++;
        }
        resMax=max(resMax,rx-i+1);
    }
    return resMax;
}

//最长相同字符字串

int longSameSubstring(string str){
    queue<int> data;

    int resMax=-1;
    int start=0;
    for(int i=0;i<str.size();){
        if(i>0){
            start=data.front();
            data.pop();
        }
        int j=start;
        while(j+1<str.size() && str[j+1]==str[j]){
            j++;
        }
        data.push(j+1);
        i=j+1;
        resMax=max(resMax,j-start+1);
    }
    return resMax;

}


int main(){
    string str;
    cin>>str;
    int resMax=longSameSubstring(str);
    cout<<resMax<<endl;
    
    return 0;
}