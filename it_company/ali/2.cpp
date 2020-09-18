#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//peding 

//http://www.mamicode.com/info-detail-1032227.html
struct ghost{
    int need;
    int killed;
};

bool comp(ghost &g1,ghost &g2){
    if(g1.killed==g2.killed)
        return g1.need<g2.need;
    return g1.killed>g2.killed;
}
bool comp0(ghost &g1,ghost &g2){
    return g1.need>g2.need;
}
int deal(vector<ghost> &v1){

    sort(v1.begin(),v1.end(),comp);
    for(int i=0;i<v1.size();i++){

    }
}
int main(){
    int n;
    int m,t;
    while(n--){
        cin>>m>>t;
        vector<ghost> data0;
        vector<ghost> data1;
        int s,k;
        ghost g1;
        for(int i=0;i<m;i++){
            cin>>s>>k;
            g1.need=s;
            g1.need=k;
            if(k==0){
                data0.push_back(g1);
            }else{
                data1.push_back(g1);
            }
        }
        
        cout<<m<<" "<<t<<endl;
    }
    return 0;
}