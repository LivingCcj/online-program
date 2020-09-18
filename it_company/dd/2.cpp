#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

#include<bits/stdc++.h>
using namespace std;
struct vaule{
    int start;
    int end;
    int spend;
    bool used;
};
bool cmp(vaule v1,vaule v2){
    return v1.spend < v2.spend;
}
const int res=INT_MAX;

int main(){
#ifndef ONLINE_JUDGE
    freopen("b.txt","r",stdin);
#endif
    int T;
    cin>>T;
    while(T--){
        int n,m,k,s,e,sp;
        cin>>n>>m>>k;
        vector<vaule> data(m);
        vaule v;
        for(int i=0;i<m;i++){
             cin>>v.start>>v.end>>v.spend;
             v.used=false;
             data[i]=v;
        }
        sort(data.begin(),data.end(),cmp);

        set<int> mark;

        if(data[0].spend<=k){
            mark.insert(data[0].start);
            mark.insert(data[0].end);
            data[0].used=true;
        }else{
            cout<<"No"<<endl;
            continue;
        }
        bool skip=false;
        int size=0;
        while(mark.size()<n){
            size=mark.size();
            for(int i=1;i<data.size();i++){
                if(data[i].used){
                    continue;
                }
                if((mark.count(data[i].start)>0 && mark.count(data[i].end)==0 )||  
                    (mark.count(data[i].end)>0 && mark.count(data[i].start)==0 ))
                    {
                        if(data[i].spend<=k){
                            mark.insert(data[i].start);
                            mark.insert(data[i].end);
                            data[i].used=true;
                        }else{
                            cout<<"No"<<endl;
                            skip=true;
                            break;
                        }
                    }
            }
            if(mark.size()==size){
                cout<<"No"<<endl;
                break;
            }

            if(skip){
                break;
            }
        }
        cout<<"Yes"<<endl;
    }

    
    return 0;
}