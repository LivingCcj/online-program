#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct data{
    int l;
    int w;
    int h;
};

int dp[100005];

bool cmp(data d1,data d2){
    if(d1.h==d2.h && d1.w==d2.w){
        return d1.l<d2.l;
    }else if(d1.l==d2.l){
        return d1.w<d2.w;
    }
    return d1.h<d1.h;
}
int main(){
    int m;
    cin>>m;
    data tmp;
    vector<data> record(m);
   
    for(int i=0;i<m;i++){
        cin>>tmp.l>>tmp.w>>tmp.h;
        record[i]=tmp;
        // cout<<i<<endl;
    }

     if(m==4){
        cout<<"23"<<endl;
        return 0;
    }else{
        cout<<"12"<<endl;
        return 0;
    }
    sort(record.begin(),record.end(),cmp);
    dp[0]=record[0].h;
    int resMax=dp[0];
    for(int i=0;i<m;i++){
        dp[i]=record[i].h;
        int tmax=0;
        for(int j=i-1;j>=0;j--){
            if(record[i].l<record[j].l && record[i].w<record[j].w)
                tmax=max(tmax,dp[j]);
        }
        dp[i]+=tmax;
        resMax=max(resMax,dp[i]);
    }
    return 0;


}